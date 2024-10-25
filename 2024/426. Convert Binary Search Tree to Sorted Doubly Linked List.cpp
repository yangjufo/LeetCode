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
        if (root == NULL) {
            return NULL;
        }
        Node *head = NULL, *prev = NULL;
        stack<Node*> stack;
        while (root != NULL || !stack.empty()) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (head == NULL) {
                head = root;
                prev = root;
            } else {
                prev->right = root;
                root->left = prev;
                prev = root;
            }
            root = root->right;
        }
        prev->right = head;
        head->left = prev;
        return head;
    }
};
