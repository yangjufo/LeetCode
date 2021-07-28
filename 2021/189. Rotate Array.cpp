class Solution {
public:
    void rotate(vector<int>& nums, int k) {        
        int n = nums.size();
        if (k == 0 || n <= 1) return;
        k %= n;
        
        vector<bool> rotated (n, false);
        for (int i = 0; i < k; i++) {
            int index = i, curr = nums[index];
            while (!rotated[index]) {
                int newIndex = (index + k) % n;
                int tmp = nums[newIndex];
                nums[newIndex] = curr;
                rotated[index] = true;
                index = newIndex;
                curr = tmp;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {        
        int n = nums.size();
        if (k == 0 || n <= 1) return;
        k %= n;
        
        int count = 0;
        for (int i = 0; count < n; i++) {
            int index = i, curr = nums[i];
            do {
                int next = (index + k) % n;
                int tmp = nums[next];
                nums[next] = curr;
                curr = tmp;
                index = next;
                count++;
            } while (index != i);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return;
        k %= nums.size();        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k == 0) return;
        k %= nums.size();
        int count = 0;
        for (int i = 0; i < nums.size() && count < nums.size(); i++) {
            int index = i, curr = nums[i];
            do {
                int next = (index + k) % nums.size();
                int tmp = nums[next];
                nums[next] = curr;
                curr = tmp;
                index = next;
                count++;
            } while (index != i);
        }    
    }
};