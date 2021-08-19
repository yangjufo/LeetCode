class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.empty()) return "";
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string res = to_string(nums[0]) + "/(";
        for (int i = 1; i < nums.size(); i++) {            
            res += to_string(nums[i]);
            if (i + 1 < nums.size()) {
                res += "/";
            }
        }
        return res + ")";
    }
};

class Point {
public:
    float maxVal, minVal;
    string maxStr, minStr;
    
    Point(float _minVal, float _maxVal, string _minStr, string _maxStr)
        : minVal(_minVal), maxVal(_maxVal), minStr(_minStr), maxStr(_maxStr) {}
    
};

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<Point*>> mem(n, vector<Point*>(n, NULL));
        return divide(nums, 0, n - 1, mem)->maxStr;
    }
    
    Point* divide(vector<int>& nums, int left, int right, vector<vector<Point*>>& mem) {
        if (mem[left][right] != NULL) {
            return mem[left][right];
        }
        if (left == right) {
            mem[left][right] = new Point(nums[left], nums[left], to_string(nums[left]), to_string(nums[left]));
            return mem[left][right];
        }
        Point* currP = new Point(std::numeric_limits<float>::max(),
std::numeric_limits<float>::min(), "", "");
        for (int i = left; i < right; i++) {            
            Point* leftP = divide(nums, left, i, mem);
            Point* rightP = divide(nums, i + 1, right, mem);
            if (currP->minVal > leftP->minVal / rightP->maxVal) {
                currP->minVal = leftP->minVal / rightP->maxVal;
                currP->minStr = leftP->minStr + "/" + (i + 1 != right ? "(" : "") + rightP->maxStr + (i + 1 != right ? ")" : "");
            }
            if (currP->maxVal < leftP->maxVal / rightP->minVal) {
                currP->maxVal = leftP->maxVal / rightP->minVal;
                currP->maxStr = leftP->maxStr + "/" + (i + 1 != right ? "(" : "") + rightP->minStr + (i + 1 != right ? ")" : "");
            }
        }
        mem[left][right] = currP;
        return currP;
    }
};