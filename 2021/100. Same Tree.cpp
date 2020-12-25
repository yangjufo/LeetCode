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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        
        queue<TreeNode*> pQueue, qQueue;
        pQueue.push(p);
        qQueue.push(q);
        while (!pQueue.empty() && !qQueue.empty()) {
            TreeNode* pNode = pQueue.front();
            TreeNode* qNode = qQueue.front();
            pQueue.pop();
            qQueue.pop();            
                        
            if (pNode->val != qNode->val) return false;
            
            if (pNode->left != NULL && qNode->left != NULL) {
                pQueue.push(pNode->left);
                qQueue.push(qNode->left);
            } else if (pNode->left != NULL || qNode->left != NULL) {
                return false;
            }
            
            if (pNode->right != NULL && qNode->right != NULL) {
                pQueue.push(pNode->right);
                qQueue.push(qNode->right);
            } else if (pNode->right != NULL || qNode->right != NULL) {
                return false;
            }                        
        }
        
        return true;
        
    }
};