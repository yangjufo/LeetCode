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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 1, res);
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == NULL) return;
        if (level > res.size()) res.push_back(vector<int>{});
        res[level - 1].push_back(root->val);
        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);        
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 1, res);
        return res;
    }
    
    void dfs(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == NULL) return;        
        if (level > res.size()) res.push_back({});
        res[level - 1].push_back(root->val);
        dfs(root->left, level + 1, res);
        dfs(root->right, level + 1, res);        
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int level) {
        if (root == NULL) return;
        if (level >= res.size()) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            res.push_back({});
            int size = treeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                res.back().push_back(node->val);
                if (node->left != NULL) {
                    treeQueue.push(node->left);
                }
                if (node->right != NULL) {
                    treeQueue.push(node->right);
                }
            }
        }
        return res;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int level) {
        if (root == NULL) return;
        if (level >= res.size()) {
            res.push_back({});
        }
        res[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    } 
};