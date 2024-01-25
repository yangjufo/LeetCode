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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> masks(10, 0);
        int count = 0;
        dfs(root, masks, count);
        return count;
    }

    void dfs(TreeNode* root, vector<int>& masks, int& count) {
        if (root == NULL) {
            return;
        }
        masks[root->val] += 1;
        if (root->left == NULL && root->right == NULL) {
            int oddCount = 0;
            for (int i = 1; i <= 9 && oddCount < 2; i++) {
                if (masks[i] % 2 != 0) {
                    oddCount += 1;
                }
            }
            if (oddCount < 2) {
                count++;
            }

        } else {
            dfs(root->left, masks, count);
            dfs(root->right, masks, count);
        }
        masks[root->val] -= 1;
    }
};