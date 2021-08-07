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
        if (root == NULL) return {};
        vector<vector<int>> res;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            res.push_back({});
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                Node* node = nodeQueue.front();
                nodeQueue.pop();
                res.back().push_back(node->val);
                for (Node* child : node->children) {
                    nodeQueue.push(child);
                }
            }
        }
        return res;
    }
};