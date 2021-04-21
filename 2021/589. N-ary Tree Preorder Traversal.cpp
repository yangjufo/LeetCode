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
    vector<int> res;
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
    
    void dfs(Node* root) {
        if (root == NULL) return;
        res.push_back(root->val);
        for (Node* child : root->children) {
            dfs(child);
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
    vector<int> preorder(Node* root) {
        if (root == NULL) return {};
        stack<Node*> nodeStack;     
        vector<int> res;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            root = nodeStack.top();
            nodeStack.pop();
            res.push_back(root->val);
            if (!root->children.empty()) {
                for (int i = root->children.size() - 1; i >= 0; i--) {
                    nodeStack.push(root->children[i]);
                }
            }
        }
        return res;
    }
};