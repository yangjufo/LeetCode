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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> res;
        root1 = GetNext(root1, s1);
        root2 = GetNext(root2, s2);
        while (root1 != NULL || root2 != NULL || !s1.empty() || !s2.empty()) {
            if (root1 == NULL || (root2 != NULL && root2->val <= root1->val)) {
                res.push_back(root2->val);
                root2 = GetNext(root2->right, s2);
            } else {
                res.push_back(root1->val);
                root1 = GetNext(root1->right, s1);
            }
        }
        return res;
    }

    TreeNode* GetNext(TreeNode* root, stack<TreeNode*>& s) {
        if (s.empty() && root == NULL) {
            return NULL;
        }
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        return root;
    }
};