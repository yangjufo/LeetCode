/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return buildTree(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(post[postEnd]);
        if (preStart < preEnd) {
            int i = postStart;
            while (i <= postEnd && post[i] != pre[preStart + 1]) {
                i++;
            }
            i -= postStart;
            root->left = buildTree(pre, preStart + 1, preStart + i + 1, post, postStart, postStart + i);
            root->right = buildTree(pre, preStart + i + 2, preEnd, post, postStart + i + 1, postEnd - 1);
        }
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int preIndex = 0, postIndex = 0;
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;
        if (root->val != post[postIndex]) {
            root->left = constructFromPrePost(pre, post);
        }
        if (root->val != post[postIndex]) {
            root->right = constructFromPrePost(pre, post);
        }
        postIndex++;
        return root;
    }        
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(pre[0]);
        stack.push(root);        
        for (int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode* node = new TreeNode(pre[i]);
            while (stack.top()->val == post[j]) {
                stack.pop();
                j++;
            }
            if (stack.top()->left == NULL) {
                stack.top()->left = node;
            } else {
                stack.top()->right = node;
            }
            stack.push(node);
        }
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       return build(preorder, 0, (int)preorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftTreeLen = 0;
        while (postEnd > 0 && preStart + leftTreeLen + 1 <= preEnd && preorder[preStart + leftTreeLen + 1] != postorder[postEnd - 1]) {
            leftTreeLen++;
        }
        root->left = build(preorder, preStart + 1, preStart + leftTreeLen, postorder, postStart, postStart + leftTreeLen - 1);
        root->right = build(preorder, preStart + leftTreeLen + 1, preEnd, postorder, postStart + leftTreeLen, postEnd - 1);
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> treeStack;
        TreeNode* root = new TreeNode(preorder[0]);
        treeStack.push(root);
        for (int i = 1, j = 0; i < preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            while (treeStack.top()->val == postorder[j]) {
                treeStack.pop();
                j++;
            }
            if (treeStack.top()->left == NULL) {
                treeStack.top()->left = node;
            } else {
                treeStack.top()->right = node;
            }
            treeStack.push(node);
        }
        return root;
    }
};