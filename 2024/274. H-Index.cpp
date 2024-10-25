class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0;
        while (i < citations.size() && i + 1 <= citations[i]) {
            i++;
        }
        return i;
    }
};