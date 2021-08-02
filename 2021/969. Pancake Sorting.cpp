class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for (int i = (int)arr.size(); i >= 1; i--) {
            int j = 0;
            while (j < i && arr[j] != i) {
                j++;
            }
            reverse(arr.begin(), arr.begin() + j + 1);
            res.push_back(j + 1);
            reverse(arr.begin(), arr.begin() + i);
            res.push_back(i);
        }
        return res;
    }
};