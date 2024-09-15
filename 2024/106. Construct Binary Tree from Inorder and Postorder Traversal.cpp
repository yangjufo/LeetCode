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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return buildTree(inorder, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1, inMap);
    }
    TreeNode* buildTree(vector<int>& inorder, int inEnd, vector<int>& postorder,
                        int postStart, int postEnd,
                        unordered_map<int, int>& inMap) {
        if (postStart > postEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inIndex = inMap[postorder[postEnd]];
        root->left = buildTree(inorder, inIndex - 1, postorder, postStart,
                               postEnd - (inEnd - inIndex) - 1, inMap);
        root->right = buildTree(inorder, inEnd, postorder, postEnd - (inEnd - inIndex),
                                postEnd - 1, inMap);
        return root;
    }
};