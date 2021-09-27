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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        TreeNode* kNode = dfs(root, k, parents);        
        if (kNode == NULL) return -1;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> treeQueue;
        visited.insert(kNode);
        treeQueue.push(kNode);
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if (node->left == NULL && node->right == NULL) {
                return node->val;
            }
            if (node->left != NULL && visited.find(node->left) == visited.end()) {
                visited.insert(node->left);
                treeQueue.push(node->left);
            }
            if (node->right != NULL && visited.find(node->right) == visited.end()) {
                visited.insert(node->right);
                treeQueue.push(node->right);
            }
            if (parents[node] != NULL && visited.find(parents[node]) == visited.end()) {
                visited.insert(parents[node]);
                treeQueue.push(parents[node]);
            }
        }
        return -1;
    }
    
    TreeNode* dfs(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root == NULL) return NULL;
        if (root->val == k) {
            return root;
        }
        if (root->left != NULL) {
            parents[root->left] = root;
            TreeNode* left = dfs(root->left, k, parents);
            if (left != NULL) {
                return left;
            }
        }
        if (root->right != NULL) {
            parents[root->right] = root;
            TreeNode* right = dfs(root->right, k, parents);
            if (right != NULL) {
                return right;
            }
        }
        return NULL;
    }
};