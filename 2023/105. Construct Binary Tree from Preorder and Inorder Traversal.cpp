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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inMap, preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }

    TreeNode* build(unordered_map<int, int>& inMap, vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = inMap[preorder[preStart]];
        root->left = build(inMap, preorder, inorder, preStart + 1, preStart + inIndex - inStart, inStart, inIndex - 1);
        root->right = build(inMap, preorder, inorder, preStart + inIndex - inStart + 1, preEnd, inIndex + 1, inEnd);
        return root;
    }
};