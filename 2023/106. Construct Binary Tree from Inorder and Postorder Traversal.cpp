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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inMap, inorder, postorder, 0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1);
    }

    TreeNode* build(unordered_map<int, int>& inMap, vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inIndex = inMap[postorder[postEnd]];
        root->left = build(inMap, inorder, postorder, inStart, inIndex - 1, postStart, postEnd - (inEnd - inIndex) - 1);
        root->right = build(inMap, inorder, postorder, inIndex + 1, inEnd, postEnd - (inEnd - inIndex), postEnd - 1);
        return root;
    }
};