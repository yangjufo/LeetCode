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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL || target == NULL) return {};
        
        unordered_map<TreeNode*, TreeNode*> parents;
        dfs(root, parents);
        vector<int> res;
        
        queue<TreeNode*> nodeQueue;
        unordered_set<TreeNode*> visited;
        nodeQueue.push(target);
        visited.insert(target);
        int dist = -1;        
        while (!nodeQueue.empty()) {
            dist++;
            if (dist == K) {
                while (!nodeQueue.empty()) {
                    res.push_back(nodeQueue.front()->val);
                    nodeQueue.pop();
                }
                break;
            }
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if (parents[node] != NULL && visited.find(parents[node]) == visited.end()) {
                    visited.insert(parents[node]);
                    nodeQueue.push(parents[node]);
                }
                if (node->left != NULL && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    nodeQueue.push(node->left);
                }
                if (node->right != NULL && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    nodeQueue.push(node->right);
                }
            }
        }
        return res;
    }
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root->left) {
            parents[root->left] = root;
            dfs(root->left, parents);
        }
        if (root->right) {
            parents[root->right] = root;
            dfs(root->right, parents);
        }
    }
};