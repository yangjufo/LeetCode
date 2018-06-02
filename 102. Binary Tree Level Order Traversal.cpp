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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;        
        vector<int> level_nodes;
        queue<TreeNode*> nodes;
        TreeNode* p;        
        int level_count = 1;
        nodes.push(root);        
        while(!nodes.empty()){    
            p = nodes.front();
            nodes.pop();                      
            level_nodes.push_back(p->val);            
            level_count--;
            if (p->left != NULL)
                nodes.push(p->left);
            if (p->right != NULL)
                nodes.push(p->right);                        
            if (level_count == 0){
                level_count = nodes.size();                
                res.push_back(level_nodes);
                level_nodes.clear();
            }
        }
        return res;        
    }
};