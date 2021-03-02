class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> counter;
        for (int c : candyType) {
            counter[c]++;
        }
        
        return min(candyType.size() / 2, counter.size());        
    }
};