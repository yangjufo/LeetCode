class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks(arr.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            for (char c : arr[i]) {
                if ((masks[i] & (1 << (c - 'a'))) != 0) {
                    masks[i] = INT_MAX;
                    break;
                }
                masks[i] |= 1 << (c - 'a');
            }
        }
        int maxLen = 0;
        dfs(arr, masks, 0, 0, 0, maxLen);
        return maxLen;
    }

    void dfs(vector<string>& arr, vector<int>& masks, int currMask, int i, int currLen, int& maxLen) {
        if (i >= masks.size()) {
            return;
        }
        if ((currMask & masks[i]) == 0 && masks[i] != INT_MAX) {
            maxLen = max(maxLen, currLen + (int)arr[i].size());
            dfs(arr, masks, currMask | masks[i], i + 1, currLen + arr[i].size(), maxLen);
        }
        dfs(arr, masks, currMask, i + 1, currLen, maxLen);
    }
};