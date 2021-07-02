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
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        int depth = max(leftDepth, rightDepth) + 1;
        while (depth > res.size()) {
            res.push_back({});
        }
        res[depth - 1].push_back(root->val);
        return depth;
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
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        collectLeaves(root);
        return res;
    }
    
    int collectLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int currLevel;
        if (root->left == NULL && root->right == NULL) {
            currLevel = 1;
        } else {
            currLevel = max(collectLeaves(root->left), collectLeaves(root->right)) + 1;
        }
        if (currLevel > res.size()) {
            res.push_back({});
        }
        res[currLevel - 1].push_back(root->val);
        return currLevel;
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
    vector<vector<int>> res;
    vector<vector<int>> findLeaves(TreeNode* root) {
        collectLeaves(root);
        return res;
    }
    
    int collectLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int currLevel = max(collectLeaves(root->left), collectLeaves(root->right)) + 1;
        if (currLevel > res.size()) {
            res.push_back({});
        }
        res[currLevel - 1].push_back(root->val);
        return currLevel;
    }
};