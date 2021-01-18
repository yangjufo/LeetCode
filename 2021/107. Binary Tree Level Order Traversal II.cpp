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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};
        stack<vector<int>> nums;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> oneLevel;
            for (int i = 0; i < size; i++) {
                root = queue.front();
                queue.pop();
                oneLevel.push_back(root->val);
                if (root->left != NULL) queue.push(root->left);
                if (root->right != NULL) queue.push(root->right);
            }            
            nums.push(oneLevel);
        }
        vector<vector<int>> ans;
        while (!nums.empty()) {
            ans.push_back(nums.top());
            nums.pop();
        }
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> res;
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});        
        while (!stack.empty()) {
            root = stack.top().first;
            int level = stack.top().second;
            stack.pop();
            if (level > res.size()) res.push_back({});
            res[level - 1].push_back(root->val);            
            if (root->right) stack.push({root->right, level + 1});
            if (root->left) stack.push({root->left, level + 1});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};