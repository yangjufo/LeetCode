/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {        
        Node* root = new Node();
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            root->val = quadTree1->val | quadTree2->val;
            root->isLeaf = true;
        } else if (quadTree1->isLeaf) {
            if (quadTree1->val == true) {
                root->val = true;
                root->isLeaf = true;
            } else {
                root = quadTree2;                
            }
        } else if (quadTree2->isLeaf) {
            if (quadTree2->val == true) {
                root->val = true;
                root->isLeaf = true;
            } else {
                root = quadTree1;
            }            
        } else {
            root->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            root->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            root->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            root->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if (root->topLeft->isLeaf && root->topRight->isLeaf && root->bottomLeft->isLeaf && root->bottomRight->isLeaf && root->topLeft->val == root->topRight->val && root->bottomLeft->val == root->topRight->val && root->bottomRight->val == root->bottomLeft->val) {
                root->val = root->topLeft->val;
                root->isLeaf = true;
                root->topLeft = root->topRight = root->bottomLeft = root->bottomRight = NULL;
            }
        }
        return root;
    }
};