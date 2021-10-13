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
    TreeNode* bstFromPreorder(vector<int>& preorder) {     
        return build(preorder, 0, (int)preorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        int mid = start + 1;
        while (mid <= end && preorder[mid] < preorder[start]) {
            mid++;
        }
        root->left = build(preorder, start + 1, mid - 1);
        root->right = build(preorder, mid, end);
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
    int index;
    TreeNode* bstFromPreorder(vector<int>& preorder) {     
        index = 0;
        return build(preorder, INT_MIN, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (index == preorder.size()) return NULL;
        int val = preorder[index];
        if (val < start || val > end) return NULL;
        index++;
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, start, val);
        root->right = build(preorder, val, end);
        return root;
    }
};