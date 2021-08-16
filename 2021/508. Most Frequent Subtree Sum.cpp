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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumCount;
        dfs(root, sumCount);
        int maxFreq = 0;
        vector<int> res;
        for (auto& iter : sumCount) {
            if (iter.second > maxFreq) {
                maxFreq = iter.second;
                res.clear();                
            }
            if (iter.second == maxFreq) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
    
    int dfs(TreeNode* root, unordered_map<int, int>& sumCount) {
        if (root == NULL) return 0;
        int sum = root->val + dfs(root->left, sumCount) + dfs(root->right, sumCount);
        sumCount[sum]++;
        return sum;
    }
};