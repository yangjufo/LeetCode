class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> sumCounter;
        int sum = 0, count = 0;
        sumCounter[0] = 1;
        for (int a : A) {
            sum = (sum + a % K + K) % K;           
            count += sumCounter[sum];
            sumCounter[sum]++;
        }
        return count;
    }
};