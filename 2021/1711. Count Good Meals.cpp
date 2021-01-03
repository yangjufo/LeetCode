class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int mod = 1000000007;
        unordered_map<int, int> dCount;
        long total = 0;
        for (int d : deliciousness) {
            int power = 1;
            for (int i = 0; i < 22; i++) {
                if (dCount.find(power - d) != dCount.end()) {
                    total += dCount[power - d];
                    total %= mod;
                }
                power <<= 1;                
            }
            dCount[d]++;            
        }
        return (int) total;
    }
};