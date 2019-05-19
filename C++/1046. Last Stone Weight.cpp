class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {        
        sort(stones.begin(), stones.end());        
        int tmp = stones.size();
        while (tmp >= 2) {
            int first = stones[stones.size() - 1];
            stones.pop_back();
            int second = stones[stones.size() - 1];
            stones.pop_back();
            tmp -= 2;
            int rem = first - second;            
            if (rem != 0) {
                stones.push_back(rem);
                sort(stones.begin(), stones.end());
                tmp += 1;
            }
        }
        if (stones.empty()) return 0;
        return stones[0];        
    }
};