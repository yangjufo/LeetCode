class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<bool> visited(A.size(), false);
        int start = 0;
        vector<int> res;
        for (int val : B) {
            int index = upper_bound(A.begin(), A.end(), val) - A.begin();
            while (visited[index] && index < A.size()) {
                index++;
            }
            if (index == A.size()) {
                while (visited[start] && start < A.size()) {
                    start++;
                }
                index = start;
            }
            visited[index] = true;
            res.push_back(A[index]);
        }
        return res;
    }
};