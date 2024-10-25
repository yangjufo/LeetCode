/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cloneMap;
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node* clone = new Node(node->val);
        cloneMap[node] = clone;
        for (Node* neigh : node->neighbors) {
            if (cloneMap.find(neigh) == cloneMap.end()) {
                clone->neighbors.push_back(cloneGraph(neigh));
            } else {
                clone->neighbors.push_back(cloneMap[neigh]);
            }
        }
        return clone;
    }
};