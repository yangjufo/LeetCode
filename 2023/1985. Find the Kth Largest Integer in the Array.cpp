class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string& left, string& right){
            return left.length() == right.length() ? left > right : left.length() > right.length();
        });
        return nums[k- 1];
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, (int)nums.size() - 1, k - 1);
    }

    string quickSelect(vector<string>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        int pI = rand() % (right - left) + left;
        pI = partition(nums, left, right, pI);
        if (pI == k) {
            return nums[pI];
        }
        if (pI < k) {
            return quickSelect(nums, pI + 1, right, k);
        }
        return quickSelect(nums, left, pI - 1, k);
    }

    int partition(vector<string>& nums, int left, int right, int pI) {
        string p = nums[pI];
        swap(nums[right], nums[pI]);
        int sI = left;
        for (int i = left; i < right; i++) {
            if (nums[i].length() > p.length() || (nums[i].length() == p.length() && nums[i] > p)) {
                swap(nums[sI], nums[i]);
                sI++;
            }
        }
        swap(nums[sI], nums[right]);
        return sI;
    }
};