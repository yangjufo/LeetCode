class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            if (numSet.count(num)) {
                return true;
            }
            numSet.insert(num);
        }        
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nSet(nums.begin(), nums.end());
        return nums.size() > nSet.size();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        return numSet.size() < nums.size();
    }
};