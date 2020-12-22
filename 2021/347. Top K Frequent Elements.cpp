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