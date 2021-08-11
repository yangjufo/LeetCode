class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int left, int right){
            if (left < 0 && right < 0) {
                return left > right;
            } else {
                return left < right;
            }
        });
        int j = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 100000) {
                continue;
            }            
            while (j < arr.size() && (arr[j] > 100000 || (arr[j] > 0 && arr[j] < arr[i] * 2) || (arr[j] < 0 && arr[j] > arr[i] * 2))) {
                j++;
            }
            if (j >= arr.size() || arr[j] != arr[i] * 2) {
                return false;
            }
            arr[j] = 100000 + 1;
        }
        return true;
    }
};

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> c;
        for (int a : arr) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};