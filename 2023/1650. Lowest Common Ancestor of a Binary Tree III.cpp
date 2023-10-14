/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root = p;
        while (root->parent != NULL) {
            root = root->parent;
        }
        return dfs(root, p, q);
    }

    Node* dfs(Node* root, Node* p, Node* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        Node* left = dfs(root->left, p, q);
        Node* right =dfs(root->right, p, q);
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
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
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p, *b = q;
        while (a != b) {
            a = a == NULL ? q : a->parent;
            b = b == NULL ? p : b->parent;
        }
        return a;
    }
};