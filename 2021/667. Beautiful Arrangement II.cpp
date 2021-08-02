class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j;) {
            if (k > 1) {
                if (k % 2 == 0) {
                    res.push_back(j);
                    j--;
                } else {
                    res.push_back(i);
                    i++;
                }
                k--;
            } else {
                res.push_back(i);
                i++;
            }            
        }
        return res;
    }
};

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int right = n - 1, left = 1;
        vector<int> res = {n};
        bool pushLeft = true;
        while (k > 1) {
            if (pushLeft) {
                res.push_back(left);
                left++;
            } else {
                res.push_back(right);
                right--;            
            }
            pushLeft = !pushLeft;
            k--;
        }      
        if (!pushLeft) {
            for (int i = left; i <= right; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = right; i >= left; i--) {
                res.push_back(i);
            }
        } 
        return res;
    }
};