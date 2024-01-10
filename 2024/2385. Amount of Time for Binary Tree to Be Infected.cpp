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
    int amountOfTime(TreeNode* root, int start) {
        int maxDis = 0;
        depth(root, start, maxDis);
        return maxDis;
    }

    int depth(TreeNode* root, int start, int& maxDis) {
        if (root == NULL) {
            return 0;
        }
        int currDepth = 0;
        int leftDepth = depth(root->left, start, maxDis), rightDepth = depth(root->right, start, maxDis);
        if (root->val == start) {
            maxDis = max(leftDepth, rightDepth);
            currDepth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            currDepth = max(leftDepth, rightDepth) + 1;
        } else {
            int dis = abs(leftDepth) + abs(rightDepth);
            maxDis = max(maxDis, dis);
            currDepth = min(leftDepth, rightDepth) - 1;
        }
        return currDepth;
    }
};