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