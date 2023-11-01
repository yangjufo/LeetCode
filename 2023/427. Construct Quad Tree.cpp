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
        return divide(grid, 0, (int)grid.size() - 1, 0, (int)grid.size() - 1);
    }

    Node* divide(vector<vector<int>>& grid, int top, int bottom, int left, int right) {
        bool same = true;
        int val = grid[top][left];
        for (int i = top; i <= bottom && same; i++) {
            for (int j = left; j <= right && same; j++) {
                if (grid[i][j] != val) {
                    same = false;
                }
            }
        }
        Node* root = new Node(val, same);
        if (same) {
            return root;
        }
        root->topLeft = divide(grid, top, top + (bottom - top) / 2, left, left + (right - left) / 2);
        root->topRight = divide(grid, top, top + (bottom - top) / 2, left + (right - left) / 2 + 1, right);
        root->bottomLeft = divide(grid, top + (bottom - top) / 2 + 1, bottom, left, left + (right - left) / 2);
        root->bottomRight = divide(grid, top + (bottom - top) / 2 + 1, bottom, left + (right - left) / 2 + 1, right);
        return root;
    }
};