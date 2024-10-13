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
    int dfs(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        if (left != right || left == -1 || right == -1) {
            return -1;
        }
        res.push_back(left + right + 1);
        return left + right + 1;

    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> res;
        dfs(root, res);
        if (res.size() < k) {
            return -1;
        }
        sort(res.begin(), res.end(), greater<int>());
        return res[k - 1];
    }
};