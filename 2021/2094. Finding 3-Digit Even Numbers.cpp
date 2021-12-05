class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10);
        for (int d : digits) {
            count[d]++;
        }
        vector<int> res;
        for (int i = 1; i <= 9; i++) {                        
            if (count[i] <= 0) continue;
            count[i]--;
            for (int j = 0; j <= 9; j++) {
                if (count[j] <= 0) continue;
                count[j]--;
                for (int k = 0; k <= 9; k+=2) {                    
                    if (count[k] <= 0) continue;                    
                    res.push_back(i * 100 + j * 10 + k);
                }
                count[j]++;
            }
            count[i]++;
        }
        return res;
    }
};