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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> preSums = {{0, 1}};
        int count = 0;
        down(root, preSums, 0, sum, count);
        return count;
    }
    
    void down(TreeNode* root, unordered_map<int, int>& preSums, int curr, int sum, int& count) {
        if (root == NULL) return;
        curr += root->val;
        count += preSums[curr - sum];
        preSums[curr]++;
        down(root->left, preSums, curr, sum, count);        
        down(root->right, preSums, curr, sum, count);
        preSums[curr]--;
    }
};