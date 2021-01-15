/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        stack<Node*> nodeStack;
        Node *dummy = new Node(0), *prev = dummy;
        while (root != NULL || !nodeStack.empty()) {
            while (root != NULL) {
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top();
            nodeStack.pop();
            prev->right = root;
            root->left = prev;
            prev = root;
            root = root->right;                        
        }        
        dummy->right->left = prev;
        prev->right = dummy->right;
        return dummy->right;        
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:    
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        Node* dummy = new Node(0);
        Node* prev = dummy;
        inorder(root, prev);
        dummy->right->left = prev;
        prev->right = dummy->right;
        return dummy->right;
    }
    
    void inorder(Node* root, Node*& prev) {
        if (root == NULL) return;
        inorder(root->left, prev);        
        prev->right = root;
        root->left = prev;
        prev = root;
        inorder(root->right, prev);
    }
};