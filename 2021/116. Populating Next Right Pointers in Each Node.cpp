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
        if (root == NULL) return NULL;
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {            
            int size = nodeQueue.size();
            Node *node, *prev;
            for (int i = 0; i < size; i++) {
                node = nodeQueue.front();
                nodeQueue.pop();
                if (i > 0) {
                    prev->next = node;
                }
                prev = node;
                if (node->left != NULL) {
                    nodeQueue.push(node->left);
                }
                if (node->right != NULL) {
                    nodeQueue.push(node->right);
                }
            }
        }
        return root;
    }
};

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
    Node* leftMost, *prev;
    Node* connect(Node* root) {
        leftMost = root;
        prev = NULL;
        while (leftMost != NULL) {
            Node* curr = leftMost;
            leftMost = NULL;
            prev = NULL;
            while (curr != NULL) {                
                connectChild(curr->left);
                connectChild(curr->right);
                curr = curr->next;                
            }
        }
        return root;
    }
    
    void connectChild(Node* root) {
        if (root == NULL) return;
        if (prev == NULL) {
            leftMost = root;
        } else {
            prev->next = root;
        }
        
        prev = root;        
    }
};

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
    Node *leftMost, *prev;
    Node* connect(Node* root) {
        leftMost = root;
        while (leftMost != NULL) {
            Node* curr = leftMost;
            leftMost = NULL;
            prev = NULL;
            while (curr != NULL) {
                connectChild(curr->left);
                connectChild(curr->right);
                curr = curr->next;
            }            
        }
        return root;
    }     
    
    void connectChild(Node* root) {
        if (root == NULL) return;
        if (leftMost == NULL) {            
            leftMost = root;
        } else {
            prev->next = root;
        }
        prev = root;
    }
};