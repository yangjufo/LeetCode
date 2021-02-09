class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int count = INT_MAX;
    
    int shortestBridge(vector<vector<int>>& A) {        
        bool first = true;
        for (int i = 0; i < A.size() && first; i++) {            
            for (int j = 0; j < A[0].size() && first; j++) {                
                if (A[i][j] == 1) {                                      
                    paint(A, i, j);                    
                    first = false;     
                    break;
                }
            }
        }                 
                
        for (int distance = 1; ; distance++) {
            for (int i = 0; i < A.size(); i++) {
                for (int j = 0; j < A[0].size(); j++) {
                    if (A[i][j] == distance + 1) {
                        if(expand(A, i, j, distance + 2)) { 
                            return distance - 1;
                        }
                    }
                }
            }
        }     
        return 0;
    }
        
    
    bool expand(vector<vector<int>>& A, int row, int col, int color) {  
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= A.size() || newCol < 0 || newCol >= A[0].size()) {
                continue;
            }            
            if (A[newRow][newCol] == 1) return true;
            if (A[newRow][newCol] == 0) {
                A[newRow][newCol] = color;
            }            
        }
        return false;
    }
    
    void paint(vector<vector<int>>& A, int row, int col) {
        A[row][col] = 2;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0], newCol = col + directions[i][1];
            if (newRow < 0 || newRow >= A.size() || newCol < 0 || newCol >= A[0].size() || A[newRow][newCol] != 1) {
                continue;
            }
            paint(A, newRow, newCol);
        }
                
    }
};