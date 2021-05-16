class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> nums2Count;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;        
        this->nums2 = nums2;
        for (int n : nums2) {
            nums2Count[n]++;
        }
    }
    
    void add(int index, int val) {
        nums2Count[nums2[index]]--;
        nums2[index] += val;
        nums2Count[nums2[index]]++;
    }
    
    int count(int tot) {
        int total = 0;
        for (int n1 : nums1) {
            if (nums2Count.find(tot - n1) != nums2Count.end()) {
                total += nums2Count[tot - n1];
            }
        }
        return total;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */