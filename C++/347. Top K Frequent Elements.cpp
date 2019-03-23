class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_count;
        vector<int> max_num;
        vector<pair<int, int>> sort_num;
        for (int i = 0; i < nums.size(); i++){
            if (num_count.count(nums[i]) == 0){
                num_count[nums[i]] = 1;
            }
            else{
                num_count[nums[i]] += 1;
            }
        }        
        for (auto val : num_count){            
            sort_num.push_back(pair<int, int>{val.first, val.second});
        }
        sort(sort_num.begin(), sort_num.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b){
            return a.second > b.second;
        });
        for (int i = 0; i < k; i ++){
            max_num.push_back(sort_num[i].first);
        }
        return max_num;
    }
};