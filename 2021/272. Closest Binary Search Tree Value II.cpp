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
    vector<int> closestKValues(TreeNode* root, double target, int k) {        
        vector<int> vals, res;
        inorder(root, vals);
        int index = lower_bound(vals.begin(), vals.end(), target) - vals.begin();   
        index = min(index, (int)vals.size() - 1);
        int left = index - 1, right = index;           
        while (res.size() < k) {            
            if (left < 0 || (right < vals.size() && abs(vals[left] - target) > abs(vals[right]) - target)) {
                res.push_back(vals[right]);
                right++;
            } else {
                res.push_back(vals[left]);
                left--;
            }
        }
        
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& vals) {
        if (root == NULL) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
    
    
};