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
private:
   bool exist(TreeNode* root, int depth, int target) {
        int left = 0, right = (int)pow(2, depth - 1) - 1;
        for (int i = 0; i < depth - 1; i++) {
            int mid = left + (right - left) / 2;
            if (mid < target) {
                root = root->right;
                left = mid + 1;
            } else {
                root = root->left;
                right = mid - 1;
            }
        }
        return root != NULL;
    }
public:
    int countNodes(TreeNode* root) {
         if (root == NULL) return 0;
        int depth = 0;
        TreeNode* node = root;
        while(node != 0) {
            depth++;
            node = node->left;
        }
        int left = 0, right = (int)pow(2, depth - 1) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (exist(root, depth, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int)pow(2, depth - 1) - 1 + left;
    }
};