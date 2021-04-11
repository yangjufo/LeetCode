class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numCounter;
        for (int n : nums) {
            numCounter[n]++;
            if (numCounter[n] >= (nums.size() + 1) / 2) return n;
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for (int n : nums) {
            if (count == 0) {
                candidate = n;
            }
            if (candidate == n) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;        
    }
};