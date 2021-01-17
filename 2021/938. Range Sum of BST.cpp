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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> stack;
        int ans = 0;
        while (root != NULL || !stack.empty()) {
            while (root != NULL) {                
                stack.push(root);                
                root = root->left;
            }            
            
            root = stack.top();
            stack.pop();
            
            if (root->val >= low && root->val <= high) {            
                ans += root->val;
            }
            root = root->right;                                                       }        
        return ans;
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0;
        stack<TreeNode*> stack;
        stack.push(root);
        int ans = 0;
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();
            if (low <= root->val && root->val <= high) {
                ans += root->val;
            }
            if (root->val > low && root->left != NULL) {
                stack.push(root->left);
            }
            if (root->val < high && root->right != NULL) {
                stack.push(root->right);
            }
        }
        return ans;
    }
};