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
        if (root == NULL) {
            return root;
        }
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            Node* prev = NULL;
            for (int i = 0; i < size; i++) {
                Node* node = queue.front();
                queue.pop();
                if (prev != NULL) {
                    prev->next = node;
                }
                prev = node;
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
        if (root == NULL) {
            return root;
        }
        Node* leftMost = root;
        while (leftMost->left != NULL) {
            Node* head = leftMost;
            while (head != NULL) {
                head->left->next = head->right;
                if (head->next != NULL) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftMost = leftMost->left;
        }
        return root;
    }
};