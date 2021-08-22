class Solution {
public:    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end());
        return backtrack(numSet, "", n);
    }
    
    string backtrack(unordered_set<string>& numSet, string curr, int n) {
        if (curr.size() >= n) {
            if (numSet.find(curr) == numSet.end()) {
                return curr;
            }
            return "";
        }
        string s = backtrack(numSet, curr + "0", n);
        if (!s.empty()) {
            return s;
        }
        return backtrack(numSet, curr + "1", n);
    }
};

class Solution {
public:    
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        for(int i = 0; i < nums.size(); i++) {
            ans+=to_string(1 - (nums[i][i] - '0'));
		}
        return ans;
    }
};