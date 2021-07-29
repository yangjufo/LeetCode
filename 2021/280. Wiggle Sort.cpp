class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), right = (n + 1) / 2;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n && right < n; i += 2) {
            swap(nums[i], nums[right]);
            right++;
        }        
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }   
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool less = true;
        for (int i = 0; i + 1 < nums.size(); i++) {
            if ((less && nums[i] > nums[i + 1]) || (!less && nums[i] < nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
            less = !less;
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool smaller = true;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if ((smaller && nums[i] > nums[i + 1]) || (!smaller && nums[i] < nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
            smaller = !smaller;
        }
    }
};