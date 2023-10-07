class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }

    int height (TreeNode* root, bool& balanced) {
        if (root == NULL) return 0;
        int left = height(root->left, balanced);
        int right = height(root->right, balanced);
        if (left - right > 1 || right - left > 1) {
            balanced = false;
        }
        return max(left, right) + 1;
    }
};
