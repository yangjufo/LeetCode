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
         stack<TreeNode*> stack;
         TreeNode* root = new TreeNode(preorder[0]);
         stack.push(root);
         for (int i = 1; i < preorder.size(); i++) {
             TreeNode* node = new TreeNode(preorder[i]);
             TreeNode* prev = NULL;
             while (!stack.empty() && stack.top()->val < preorder[i]) {
                prev = stack.top();
                stack.pop();
             }
             if (prev != NULL) {
                 prev->right = node;
             } else if (!stack.empty()) {
                 stack.top()->left = node;
             }
             stack.push(node);
         }
         return root;
    }
};