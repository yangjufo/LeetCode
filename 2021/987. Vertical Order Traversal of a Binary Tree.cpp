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
    vector<vector<int>> verticalTraversal(TreeNode* root) {        
        if (root == NULL) return {};             
        
        queue<TreeNode*> nodeQueue;
        queue<int> vQueue;
        nodeQueue.push(root);
        vQueue.push(0);        
        
        vector<vector<TreeNode*>> hMap;
        unordered_map<TreeNode*, int> vMap;
        
        int minV = 0, maxV = 0, currV = 0, currH = -1;
        while (!nodeQueue.empty()) {
            currH++;
            hMap.push_back({});
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                root = nodeQueue.front();
                nodeQueue.pop();
                currV = vQueue.front();
                vQueue.pop();                
                vMap[root] = currV;
                hMap[currH].push_back(root);

                minV = min(minV, currV);
                maxV = max(maxV, currV);

                if (root->left) {
                    nodeQueue.push(root->left);
                    vQueue.push(currV - 1);
                }
                if (root->right) {
                    nodeQueue.push(root->right);
                    vQueue.push(currV + 1);
                }
            }                        
        }
        
        vector<vector<int>> ans(maxV - minV + 1, vector<int>{});
        for (int i = 0; i < hMap.size(); i++) {
            sort(hMap[i].begin(), hMap[i].end(), 
                 [](TreeNode* l, TreeNode* r) { return l->val < r->val; });
            for (TreeNode* node : hMap[i]) {
                ans[vMap[node]-minV].push_back(node->val);
            }            
        }
        return ans;        
    }
};