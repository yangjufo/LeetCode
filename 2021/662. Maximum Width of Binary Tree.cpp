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
    vector<pair<unsigned long long, unsigned long long>> levelDiff;    
    int widthOfBinaryTree(TreeNode* root) {        
        dfs(root, 1, 0);
        unsigned long long maxDiff = 0;
        for (int i = 0; i < levelDiff.size(); i++) {
            maxDiff = max(maxDiff, levelDiff[i].second - levelDiff[i].first + 1);
        }
        return maxDiff;
    }
    
    void dfs(TreeNode* root, unsigned long long index, int row) {
        if (root == NULL) return;
        if (row >= levelDiff.size()) {
            levelDiff.push_back({index, index});
        }
        levelDiff[row].first = min(index, levelDiff[row].first);
        levelDiff[row].second = max(index, levelDiff[row].second);
        dfs(root->left, index * 2, row + 1);
        dfs(root->right, index * 2 + 1, row + 1);
    }
};