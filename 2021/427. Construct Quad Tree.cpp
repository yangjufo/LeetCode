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
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n - 1, n - 1);
    }
    
    Node* build(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {        
        if (r1 == r2) {
            return new Node(grid[r1][c1], true);
        }
        Node* root = new Node();        
        Node* topLeft = build(grid, r1, c1, r1 + (r2 - r1) / 2, c1 + (c2 - c1) / 2);
        Node* topRight = build(grid, r1, c1 + (c2 - c1) / 2 + 1, r1 + (r2 - r1) / 2, c2);
        Node* bottomLeft = build(grid, r1 + (r2 - r1) / 2 + 1, c1, r2, c1 + (c2 - c1) / 2);
        Node* bottomRight = build(grid, r1 + (r2 - r1) / 2 + 1, c1 + (c2 - c1) / 2 + 1, r2, c2);        
        if (topLeft->val == topRight->val && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val && topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {            
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            root->val = grid[r1][c1];
            root->isLeaf = true;     
        } else {
            root->topLeft = topLeft;
            root->topRight = topRight;
            root->bottomLeft = bottomLeft;
            root->bottomRight = bottomRight;
        }
        return root;
    }
    
};