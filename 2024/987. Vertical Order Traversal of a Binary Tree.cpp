/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<vector<int>>> left, right;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 0});
        int row = -1;
        while (!queue.empty()) {
            int size = queue.size();
            row += 1;
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front().first;
                int col = queue.front().second;
                queue.pop();
                if (col >= 0) {
                    if (right.size() <= col) {
                        right.push_back({});
                    }
                    while (right[col].size() <= row) {
                        right[col].push_back({});
                    }
                    right[col][row].push_back(node->val);
                } else {
                    if (left.size() <= abs(col) - 1) {
                        left.push_back({});
                    }
                    while (left[abs(col) - 1].size() <= row) {
                        left[abs(col) - 1].push_back({});
                    }
                    left[abs(col) - 1][row].push_back(node->val);
                }
                if (node->left != NULL) {
                    queue.push({node->left, col - 1});
                }
                if (node->right != NULL) {
                    queue.push({node->right, col + 1});
                }
            }
        }
        vector<vector<int>> res;
        for (int i = left.size() - 1; i >= 0; i--) {
            res.push_back({});
            for (int j = 0; j < left[i].size(); j++) {
                sort(left[i][j].begin(), left[i][j].end());
                for (int v : left[i][j]) {
                    res.back().push_back(v);
                }
            }
        }
        for (int i = 0; i < right.size(); i++) {
            res.push_back({});
            for (int j = 0; j < right[i].size(); j++) {
                sort(right[i][j].begin(), right[i][j].end());
                for (int v : right[i][j]) {
                    res.back().push_back(v);
                }
            }
        }
        return res;
    }
};