/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == NULL) return NULL;
        TreeNode* bRoot = new TreeNode(root->val), *prev = bRoot;
        for (int i = 0; i < root->children.size(); i++) {
            TreeNode* curr = encode(root->children[i]);
            if (i == 0) {
                prev->left = curr;
            } else {
                prev->right = curr;
            }            
            prev = curr;
        }
        return bRoot;        
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == NULL) return NULL;
        Node* nRoot = new Node(root->val);
        TreeNode* child = root->left;
        while (child != NULL) {
            nRoot->children.push_back(decode(child));
            child = child->right;
        }
        return nRoot;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));