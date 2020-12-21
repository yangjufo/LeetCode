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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> nodeMap;
        return cloneNode(node, nodeMap);
    }
    
    Node* cloneNode(Node* node, unordered_map<Node*, Node*>& nodeMap) {
        if (node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeMap[node] = clone;
        for (Node* neighbor : node->neighbors) {
            if (!nodeMap.count(neighbor)) {
                cloneNode(neighbor, nodeMap);
            }
            clone->neighbors.push_back(nodeMap[neighbor]);
        }
        return clone;
    }
    
};