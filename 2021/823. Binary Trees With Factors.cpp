class Solution {
public:
    int mod = 1'000'000'007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int N = arr.size();
        unordered_map<int, int> indexes;        
        vector<long long> dp(N, 1);
        for (int i = 0; i < N; i++) {
            indexes[arr[i]] = i;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {                    
                    int another = arr[i] / arr[j];
                    if (indexes.find(another) != indexes.end()) {
                        dp[i] = (dp[i] + ((dp[j] % mod) * (dp[indexes[another]] % mod)) % mod) % mod;
                    }                    
                }
            }
        }
        int sum = 0;
        for (int c : dp) {
            sum = (sum + c) % mod;
        }
        return sum;
    }
};