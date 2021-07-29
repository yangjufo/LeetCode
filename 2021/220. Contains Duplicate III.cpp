class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<long, long> buckets;
        long w = (long) t + 1;
        for (int i = 0; i < nums.size(); i++) {
            long m = getId(nums[i], w);
            if (buckets.find(m) != buckets.end()) return true;
            if (buckets.find(m - 1) != buckets.end() && abs(nums[i] - buckets[m - 1]) < w) return true;
            if (buckets.find(m + 1) != buckets.end() && abs(nums[i] - buckets[m + 1]) < w) return true;
            buckets[m] = nums[i];
            if (i >= k) {
                buckets.erase(getId(nums[i - k], w));
            }
        }
        return false;
    }
    
    long getId(long x, long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long, int>> numIndexes;
        for (int i = 0; i < nums.size(); i++) {
            numIndexes.push_back({nums[i], i});
        }
        sort(numIndexes.begin(), numIndexes.end());
        for (int i = 0; i < numIndexes.size(); i++) {
            for (int j = i + 1; j < numIndexes.size(); j++) {
                long diff = abs(numIndexes[i].first - numIndexes[j].first);
                if (diff > t) break;
                if (abs(numIndexes[i].second - numIndexes[j].second) <= k) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            auto iter = window.lower_bound(nums[i]);
            if ((iter != window.end() && *iter <= nums[i] + t) || (iter != window.begin() && nums[i] <= *prev(iter) + t)) {
                return true;
            }            
            window.insert(nums[i]);
        }
        return false;
    }
};