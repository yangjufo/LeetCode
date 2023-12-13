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
        while (leftMost != NULL) {
            while (leftMost != NULL && leftMost->left == NULL && leftMost->right == NULL) {
                leftMost = leftMost->next;
            }
            Node* head = leftMost;
            while (head != NULL) {
                Node* currChild = NULL;
                if (head->left != NULL) {
                    if (head->right != NULL) {
                        head->left->next = head->right;
                        currChild = head->right;
                    } else {
                        currChild = head->left;
                    }
                } else {
                    currChild = head->right;
                }
                Node* next = head->next;
                while (next != NULL && next->left == NULL && next->right == NULL) {
                    next = next->next;
                }
                if (next != NULL) {
                    if (next->left != NULL) {
                        currChild->next = next->left;
                    } else {
                        currChild->next = next->right;
                    }
                }
                head = next;
            }
            if (leftMost != NULL) {
                if (leftMost->left != NULL) {
                    leftMost = leftMost->left;
                } else {
                    leftMost = leftMost->right;
                }
            }
        }
        return root;
    }
};