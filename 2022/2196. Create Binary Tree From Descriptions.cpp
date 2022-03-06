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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        vector<int> mark(100001, -1);
        for (vector<int>& d : descriptions) {
            if (mark[d[0]] == -1) {
                mark[d[0]] = 0;
            }
            mark[d[1]] = 1;
            if (nodeMap.find(d[0]) == nodeMap.end()) {
                nodeMap[d[0]] = new TreeNode(d[0]);
            }
            if (nodeMap.find(d[1]) == nodeMap.end()) {
                nodeMap[d[1]] = new TreeNode(d[1]);
            }
            if (d[2] == 0) {
                nodeMap[d[0]]->right = nodeMap[d[1]];
            } else {
                nodeMap[d[0]]->left = nodeMap[d[1]];
            }
        }
        for (int i = 0; i < 100001; i++) {
            if (mark[i] == 0) {
                return nodeMap[i];
            }
        }
        return NULL;
    }
};