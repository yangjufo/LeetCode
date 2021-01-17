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
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node* node = queue.front();
                queue.pop();
                if (i == size - 1 || queue.empty()) {
                    node->next = NULL;
                } else {
                    node->next = queue.front();
                }
                if (node->left != NULL) {
                    queue.push(node->left);
                }
                if (node->right != NULL) {
                    queue.push(node->right);
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
    Node* connect(Node* root) {                
        Node *leftMost = root, *prev = NULL;        
        while (leftMost != NULL) {          
            Node* curr = leftMost;
            leftMost = NULL;
            prev = NULL;
            while (curr != NULL) {
                connectChild(leftMost, prev, curr->left);
                connectChild(leftMost, prev, curr->right);
                curr = curr->next;
            }            
        }
        return root;
    }
    
    void connectChild(Node*& leftMost, Node*& prev, Node* root) {
        if (root == NULL) return;
        if (prev != NULL) {
            prev->next = root;
        } else {
            leftMost = root;
        }        
        
        prev = root;
    }
    
};