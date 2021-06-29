class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        vector<int> res;
        for (auto& iter : count) {
            if (iter.second == 1) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long aXorb = 0;  // the result of a xor b;
        for (auto item : nums) aXorb ^= item;
        int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;  // the last bit that a diffs b
        int intA = 0, intB = 0;
        for (auto item : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (item & lastBit) intA = intA ^ item;
            else intB = intB ^ item;
        }
        return vector<int>{intA, intB};  
    }
};