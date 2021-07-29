class Solution {
public:
    bool isAdditiveNumber(string num) {        
        return backtrack(num, 0, -1, -1, 0);
    }
    
    bool backtrack(string& num, int index, long long prev1, long long prev2, int numCount) {
        if (index >= num.length() && numCount >= 3) return true;        
        long long curr = 0;
        for (int i = index; i < min(num.length(), index + num.length() / 2); i++) {
            curr = curr * 10 + (num[i] - '0');
            if ((prev1 < 0 || prev2 < 0 || prev1 + prev2 == curr) && (num[index] != '0' || i == index) && backtrack(num, i + 1, prev2, curr, numCount + 1)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isAdditiveNumber(string num) {
        return backtrack(num, 0, -1, -1, 0);
    }
    
    bool backtrack(string& num, int index, long long prev2, long prev1, int count) {
        if (index >= num.length()) return count >= 3;        
        long long curr = 0;
        for (int i = index; i <= min((int)num.length(), index + (int)num.length() / 2); i++) {
            curr = curr * 10 + num[i] - '0';
            if ((prev2 == -1 || prev2 + prev1 == curr) && backtrack(num, i + 1, prev1, curr, count + 1)) {
                return true;
            }            
            if (num[index] == '0') {
                break;
            }
        }
        return false;
    }
};