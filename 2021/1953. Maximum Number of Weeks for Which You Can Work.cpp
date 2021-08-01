class Solution {
public:
    long long numberOfWeeks(vector<int>& ms) {        
        long long total = 0;
        int maxCount = 0;
        for (int i = 0; i < ms.size(); i++) {
            total += ms[i];
            maxCount = max(maxCount, ms[i]);
        }
        total -= maxCount;
        return total + (maxCount - 1 > total ? total + 1 : maxCount);
    }
};