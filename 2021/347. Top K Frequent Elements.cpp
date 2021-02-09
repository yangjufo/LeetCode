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