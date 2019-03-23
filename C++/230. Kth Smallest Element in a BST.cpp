/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stack;            
        int count = 0;
        while (root != NULL || !stack.empty()){
            while (root != NULL){
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            count++;
            if (count == k)
                return root->val;
            root = root->right;            
        }
    }
};