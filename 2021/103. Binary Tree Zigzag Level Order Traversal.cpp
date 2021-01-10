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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        bool leftToRight = true;        
        while (!queue.empty()) {            
            vector<int> tmp;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                root = queue.front();
                queue.pop();         
                tmp.push_back(root->val);
                if (root->left) queue.push(root->left);
                if (root->right) queue.push(root->right);
            }
            if (!leftToRight) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};