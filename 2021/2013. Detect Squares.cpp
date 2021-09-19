class DetectSquares {
public:
    vector<vector<int>> points;
    DetectSquares() {
        points.resize(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;        
    }
    
    int count(vector<int> point) {
        int total = 0, x = point[0], y = point[1];
        for (int i = 0; i <= 1000; i++) {
            if (i < x) {
                if (y - (x - i) >= 0) {
                    total += points[i][y] * points[x][y - (x - i)] * points[i][y - (x - i)];
                }                
                if (y + (x - i) <= 1000) {
                    total += points[i][y] * points[x][y + (x - i)] * points[i][y + (x - i)];
                }
            } else if (i > x) {
                if (y - (i - x) >= 0) {
                    total += points[i][y] * points[x][y - (i - x)] * points[i][y - (i - x)];
                }                
                if (y + (i - x) <= 1000) {
                    total += points[i][y] * points[x][y + (i - x)] * points[i][y + (i - x)];
                }
            }
        }
        return total;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */