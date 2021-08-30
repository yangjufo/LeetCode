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
    bool checkEqualTree(TreeNode* root) {
        int total = sum(root);        
        if (abs(total) % 2 == 1) return false;
        bool found = false;
        dfs(root, root, total / 2, found);
        return found;
    }
    
    int sum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    int dfs(TreeNode* oldRoot, TreeNode* root, int target, bool& found) {
        if (root == NULL) return 0;
        int curr = root->val + dfs(oldRoot, root->left, target, found) + dfs(oldRoot, root->right, target, found);
        if (curr == target && root != oldRoot) {
            found = true;
        }
        return curr;
    }
};