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
        return build(nums, 0, (int) nums.size() - 1);
    }
    
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = build(nums, left, maxIndex- 1);
        root->right = build(nums, maxIndex + 1, right);
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
        stack<TreeNode*> nodes;
        for (int n : nums) {
            TreeNode* curr = new TreeNode(n);
            while (!nodes.empty() && nodes.top()->val < n) {
                curr->left = nodes.top();
                nodes.pop();
            }
            if (!nodes.empty()) {
                nodes.top()->right = curr;
            }
            nodes.push(curr);
        }
        while (nodes.size() > 1) {
            nodes.pop();
        }
        return nodes.top();
    }
};