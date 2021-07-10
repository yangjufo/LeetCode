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
    int maxCount = 0;
    int largestBSTSubtree(TreeNode* root) {
        largestBSTtree(root);
        return maxCount;
    }
    
    array<int, 3> largestBSTtree(TreeNode* root) {
        if (root == NULL) return {0, 0, 0};
        auto left = largestBSTtree(root->left);
        auto right = largestBSTtree(root->right);
        if (left[2] < 0 || right[2] < 0) {
            return {0, 0, -1};
        }
        if (left[2] == 0 && right[2] == 0) {
            maxCount = max(maxCount, 1);
            return {root->val, root->val, 1};
        }        
        if (left[2] == 0) {
            if (right[0] <= root->val) {
                return {0, 0, -1};
            } else {
                maxCount = max(maxCount, right[2] + 1);
                return {root->val, right[1], right[2] + 1};
            }
        } 
        if (right[2] == 0) {
            if (left[1] >= root->val ) {
                return {0, 0, -1};
            } else {
                maxCount = max(maxCount, left[2] + 1);
                return {left[0], root->val, left[2] + 1};
            }
        }
        
        if (left[1] >= root->val || right[0] <= root->val) {
            return {0, 0, -1};
        }
        maxCount = max(maxCount, left[2] + right[2] + 1);
        return {left[0], right[1], left[2] + right[2] + 1};
        
    }
};