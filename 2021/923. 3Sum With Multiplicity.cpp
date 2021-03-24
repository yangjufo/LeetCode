class Solution {
public:
    int mod = 1'000'000'007;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> oneNumCount, twoNumCount;
        int sumCount = 0;
        for (int a : arr) {
            sumCount = (sumCount + twoNumCount[target - a]) % mod;
            for (auto& iter : oneNumCount) {
                twoNumCount[iter.first + a] = (twoNumCount[iter.first + a] + iter.second) % mod;
            }            
            oneNumCount[a] = (oneNumCount[a] + 1) % mod;
        }
        return sumCount;
    }
};

class Solution {
public:
    int mod = 1'000'000'007;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> count;
        for (int a : arr) {
            count[a] = (count[a] + 1) % mod;
        }
        int sumCount = 0;
        for (auto& c1 : count) {
            for (auto& c2 : count) {
                int i = c1.first, j = c2.first, k = target - i - j;
                if (count.find(k) == count.end()) continue;
                if (i == j && j == k) {
                    sumCount = (sumCount + (count[i]) * (count[i] - 1) * (count[i] - 2) / 6 % mod) % mod;
                } else if (i == j && j != k) {
                    sumCount = (sumCount + (count[i]) * (count[i] - 1) / 2 * (count[k]) % mod) % mod;
                } else if (i < j && j < k) {
                    sumCount = (sumCount + count[i] * count[j] * count[k] % mod) % mod;
                }
            }
        }
        return sumCount;
    }
};