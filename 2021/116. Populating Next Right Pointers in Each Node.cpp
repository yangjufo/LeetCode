/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* leftMost = root, *prev = NULL;
        while (leftMost != NULL) {
            Node* curr = leftMost;
            leftMost = NULL;
            prev = NULL;
            while (curr != NULL) {                
                connectChild(curr->left, prev, leftMost);
                connectChild(curr->right, prev, leftMost);
                curr = curr->next;                
            }
        }
        return root;
    }
    
    void connectChild(Node* root, Node*& prev, Node*& leftMost) {
        if (root == NULL) return;
        if (prev != NULL) {
            prev->next = root;
        } else {
            leftMost = root;
        }
        
        prev = root;
    }
    
};

