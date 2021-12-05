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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* p = common(root, startValue, destValue);
        string path;
        string left = string(depth(p, startValue), 'U');
        dfs(p, destValue, path);
        return left + path;
    }
    
    TreeNode* common(TreeNode* root, int startValue, int destValue) {
        if (root == NULL) return NULL;
        if (root->val == startValue || root->val == destValue) return root;
        TreeNode* left = common(root->left, startValue, destValue);
        TreeNode* right = common(root->right, startValue, destValue);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
    
    int depth(TreeNode* root, int startValue) {
        if (root == NULL) return INT_MAX;  
        if (root->val == startValue) return 0;     
        int left = depth(root->left, startValue);
        if (left != INT_MAX) {
            return left + 1;
        }
        int right = depth(root->right, startValue);
        if (right != INT_MAX) {
            return right + 1;
        }
        return INT_MAX;
    }
    
    bool dfs(TreeNode* root, int value, string& path) {
        if (root == NULL) return false;
        if (root->val == value) {            
            return true;
        }
        path.push_back('L');
        auto left = dfs(root->left, value, path);
        if (left) {
            return true;
        }
        path.back() = 'R';
        auto right = dfs(root->right, value, path);
        if (right) {
            return true;
        }
        path.pop_back();
        return false;
    }
};