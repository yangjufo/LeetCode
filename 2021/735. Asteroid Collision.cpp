class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int a : asteroids) {            
            while (!res.empty() && a < 0 && res.back() > 0 && abs(a) > abs(res.back())) {
                res.pop_back();
            }            
            if (!res.empty() && a < 0 && res.back() > 0 && abs(a) == abs(res.back())) {
                res.pop_back();
            } else if (res.empty() || (a < 0 && res.back() < 0) || a > 0) {
                res.push_back(a);
            }
        }
        return res;
    }
};