/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, index);
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart,
                        unordered_map<int, int>& index) {
        if (preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = index[preorder[preStart]];
        root->left =
            buildTree(preorder, preStart + 1, preStart + inIndex - inStart,
                      inorder, inStart, index);
        root->right = buildTree(preorder, preStart + inIndex - inStart + 1,
                                preEnd, inorder, inIndex + 1, index);
        return root;
    }
};