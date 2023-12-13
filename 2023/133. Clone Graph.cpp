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
        if (node == NULL) {
            return NULL;
        }
        unordered_map<Node*, Node*> cm;
        queue<Node*> queue;
        queue.push(node);
        cm[node] = new Node(node->val);
        while (!queue.empty()) {
            Node* curr = queue.front();
            queue.pop();
            for (Node* next : curr->neighbors) {
                if (cm.find(next) == cm.end()) {
                    cm[next] = new Node(next->val);
                    queue.push(next);
                }
                cm[curr]->neighbors.push_back(cm[next]);
            }
        }
        return cm[node];
    }
};