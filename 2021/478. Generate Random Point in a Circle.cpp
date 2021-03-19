class Solution {
public:    
    double radius, x_center, y_center, PI;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        PI = atan(1)*4;
    }
    
    vector<double> randPoint() {
        double angle =  ((double) rand() / RAND_MAX) * 2 * PI, len = sqrt(((double) rand() / RAND_MAX)) * radius;
        return {x_center + len * cos(angle), y_center + len * sin(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */