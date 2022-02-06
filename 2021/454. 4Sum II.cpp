class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ABCount, CDCount;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                ABCount[A[i] + B[j]]++;
                CDCount[C[i] + D[j]]++;
            }
        }

        int count = 0;
        for (auto& iter : ABCount) {
            count += CDCount[-iter.first] * iter.second;
        }
        return count;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum1;
        for (int i : nums1) {
            for (int j : nums2) {
                sum1[i + j]++;
            }
        }
        int res = 0;
        for (int i : nums3) {
            for (int j : nums4) {
                if (sum1.find(-i-j) != sum1.end()) {
                    res += sum1[-i-j];
                }
            }
        }
        return res;
    }
};