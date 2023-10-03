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
    vector<TreeNode*> generateSubtrees(int start, int end) {
        if (start > end) {
            return {NULL};
        }
        vector<TreeNode*> ret;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = generateSubtrees(start, i - 1);
            vector<TreeNode*> rights = generateSubtrees(i + 1, end);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ret.push_back(root);
                }

            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateSubtrees(1, n);
    }
};