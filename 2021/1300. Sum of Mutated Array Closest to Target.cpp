class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int sum = 0, diff = 1e5, res = 0, n = arr.size();
        for (int i = 0; i < n && diff > 0; i++) {
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            int minValue = (i == 0 ? 0 : arr[i - 1]), maxValue = arr[i];           
            int candidates[4] = {minValue, (target - sum) / (n - i), (target - sum) / (n - i) + 1, maxValue};
            for (int cand : candidates) {
                if (cand > maxValue || cand < minValue) continue;
                int candDiff = abs(sum + cand * (n - i) - target);
                if (candDiff < diff) {
                    diff = candDiff;
                    res = cand;
                }
            }
            sum += arr[i];
        }
        return res;
    }
};

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size(), sum = 0, minDiff = target, res = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() && minDiff > 0; i++) {
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            int minVal = i == 0 ? 0 : arr[i - 1], maxVal = arr[i];
            int cands[4] = {minVal, (target - sum) / (n - i), (target - sum) / (n - i) + 1, maxVal};
            for (int cand : cands) {
                if (cand < minVal || cand > maxVal) continue;
                int candDiff = abs(sum + cand * (n - i) - target);
                if (candDiff < minDiff) {
                    minDiff = candDiff;
                    res = cand;
                }
            }
            sum += arr[i];
        }
        return res;
    }
};