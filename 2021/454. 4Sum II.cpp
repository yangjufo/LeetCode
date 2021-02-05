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