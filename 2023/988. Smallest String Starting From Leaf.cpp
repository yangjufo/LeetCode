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
    string smallestFromLeaf(TreeNode* root) {
        string mins, curr;
        dfs(root, mins, curr);
        return mins;
    }

    void dfs(TreeNode* root, string& mins, string& curr) {
        curr += root->val + 'a';
        if (root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end());
            if (mins.empty() || curr < mins) {
                mins = curr;
            }
            reverse(curr.begin(), curr.end());
            return;
        }
        if (root->left != NULL) {
            dfs(root->left, mins, curr);
            curr.pop_back();
        }
        if (root->right != NULL) {
            dfs(root->right, mins, curr);
            curr.pop_back();
        }

    }
};