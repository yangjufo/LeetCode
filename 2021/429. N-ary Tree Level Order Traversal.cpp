/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(Node* root, int level, vector<vector<int>>& res) {
        if (root == NULL) return;
        if (level >= res.size()) {
            res.push_back({});            
        }
        res[level].push_back(root->val);
        for (Node* child : root->children) {
            dfs(child, level + 1, res);
        }
    }
};