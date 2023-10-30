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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, (int)nums.size() - 1);
    }

    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int maxI = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxI]) {
                maxI = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxI]);
        root->left = construct(nums, left, maxI - 1);
        root->right = construct(nums, maxI + 1, right);
        return root;
    }
};

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stack;
        for (int i = 0; i < nums.size(); i++) {
            TreeNode* root = new TreeNode(nums[i]);
            while (!stack.empty() && stack.top()->val < nums[i]) {
                root->left = stack.top();
                stack.pop();
            }

            if (!stack.empty()) {
                stack.top()->right = root;
            }
            stack.push(root);
        }
        while (stack.size() > 1) {
            stack.pop();
        }
        return stack.top();
    }
};