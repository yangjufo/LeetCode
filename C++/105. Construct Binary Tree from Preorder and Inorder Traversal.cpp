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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;   
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);        
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if (preStart > preEnd || inStart > inEnd)
            return NULL;                
        TreeNode *root;
        root = new TreeNode(preorder[preStart]);                        
        int i = inStart;
        while(inorder[i] != preorder[preStart]){
            i++;
        }        
        root->left = buildTree(preorder, inorder, preStart + 1, preStart + i - inStart, inStart, i - 1);
        i = i + 1;        
        root->right = buildTree(preorder, inorder, preStart + i - inStart, preEnd, i, inEnd);        
        return root;
    }
};