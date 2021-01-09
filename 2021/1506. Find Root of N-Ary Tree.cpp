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
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> children;
        for (Node* node : tree) {
            for (Node* child : node->children) {
                children.insert(child);
            }
        }
        for (Node* node : tree) {
            if (children.find(node) == children.end()) return node;
        }
        return NULL;
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
    Node* findRoot(vector<Node*> tree) {
        int xo = 0;
        for (Node* node : tree) {
            xo ^= node->val;
            for (Node* child : node->children) {
                xo ^= child->val;
            }
        }
        
        for (Node* node : tree) {
            if (node->val == xo) return node;
        }
        return NULL;
    }
};