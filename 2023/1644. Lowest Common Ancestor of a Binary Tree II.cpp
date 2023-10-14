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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              bool pf = false, qf = false;
              TreeNode* cand = lca(root, p, pf, q, qf);
              return pf && qf ? cand : NULL;
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, bool& pf, TreeNode* q, bool& qf) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* left = lca(root->left, p, pf, q, qf), *right = lca(root->right, p, pf, q, qf);
        if (root == p) {
            pf = true;
            return root;
        }
        if (root == q) {
            qf = true;
            return root;
        }
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        return root;
    }
};