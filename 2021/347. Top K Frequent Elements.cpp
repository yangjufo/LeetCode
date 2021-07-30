class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for (int n : nums) {
            numCount[n]++;
        }
        
        auto Compare = [](int* a, int* b) { return a[1] > b[1]; };
        
        priority_queue<int*, vector<int*>, decltype(Compare)> maxCountHeap(Compare);
        for (auto const& iter : numCount) {
            maxCountHeap.push(new int[]{iter.first, iter.second});            
            if (maxCountHeap.size() > k) {
                maxCountHeap.pop();
            }
        }
        
        vector<int> ans;
        while (!maxCountHeap.empty()) {
            ans.push_back(maxCountHeap.top()[0]);
            maxCountHeap.pop();
        }
            
        return ans;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        for (int n : nums) {
            numCount[n]++;
        }
        
        auto comparator = [](pair<int, int> left, pair<int, int> right) {
          return left.second > right.second;  
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (auto& iter : numCount) {
            pq.push({iter.first, iter.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        auto comparator = [](pair<int, int> left, pair<int ,int> right) {
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (auto& iter : count) {
            pq.push({iter.first, iter.second});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};


class Solution {
public:
    vector<int> unique;
    unordered_map<int, int> count;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n : nums) {
            count[n]++;
        }
        for (auto& iter : count) {
            unique.push_back(iter.first);
        }
        
        quickSelect(0, (int)unique.size() - 1, k);
        while (unique.size() > k) {
            unique.pop_back();
        }
        return unique;
    }
    
    void quickSelect(int left, int right, int k) {
        if (left >= right) return;
        
        int pivot = rand() % (right - left + 1) + left;
        
        pivot = partition(left, right, pivot);
        
        if (pivot == k) return;
        if (pivot > k) {
            quickSelect(left, pivot - 1, k);
        } else {
            quickSelect(pivot + 1, right, k);
        }        
    }
    
    int partition(int left, int right, int pivot) {
        swap(unique[pivot], unique[right]);
        
        int largeIndex = left;
        for (int i = left; i < right; i++) {
            if (count[unique[i]] > count[unique[right]]) {
                swap(unique[i], unique[largeIndex]);
                largeIndex++;
            }
        }
        
        swap(unique[largeIndex], unique[right]);
        return largeIndex;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freqBucket(nums.size() + 1);
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        for (auto& iter : count) {
            freqBucket[iter.second].push_back(iter.first);
        }
        
        vector<int> res;
        for (int i = nums.size(); i >= 1 && res.size() < k; i--) {
            if (!freqBucket[i].empty()) {
                for (int j = 0; j < freqBucket[i].size() && res.size() < k; j++) {
                    res.push_back(freqBucket[i][j]);
                }
            }
        }
        return res;
    }
};