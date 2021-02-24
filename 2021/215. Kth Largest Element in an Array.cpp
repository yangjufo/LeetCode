class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int kSmallest) {
        if (left == right) return nums[left];
        
        int pivotIndex = rand() % (right - left) + left;
        
        pivotIndex = partition(nums, left, right, pivotIndex);
        
        if (kSmallest == pivotIndex) {
            return nums[kSmallest];
        }
        if (kSmallest < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, kSmallest);
        }
        return quickSelect(nums, pivotIndex + 1, right, kSmallest);
    }
    
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivot = nums[pivotIndex];
        swap(nums, pivotIndex, right);
        
        int storeIndex = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] < pivot) {
                swap(nums, storeIndex, i);
                storeIndex++;
            }
        }
        
        swap(nums, storeIndex, right);
        
        return storeIndex;
    }
    
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int kSmallest) {
        if (left >= right) return nums[left];
        
        int pivotIndex = rand() % (right - left) + left;
        
        pivotIndex = partition(nums, left, right, pivotIndex);
        
        if (pivotIndex == kSmallest) {
            return nums[pivotIndex];
        }
        
        if (pivotIndex > kSmallest) {
            return quickSelect(nums, left, pivotIndex - 1, kSmallest);
        }
        return quickSelect(nums, pivotIndex + 1, right, kSmallest);
        
    }
    
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        swap(nums[right], nums[pivotIndex]);
        
        int smallIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[right]) {
                swap(nums[i], nums[smallIndex]);
                smallIndex++;
            }
        }
        
        swap(nums[smallIndex], nums[right]);
        return smallIndex;        
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        
        int pivotIndex = rand() % (right - left) + left;
        
        pivotIndex = partition(nums, left, right, pivotIndex);
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1 , right);
    }
    
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        swap(nums[right], nums[pivotIndex]);
        
        int smallIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[right]) {
                swap(nums[i], nums[smallIndex]);
                smallIndex++;
            }
        }
        
        swap(nums[smallIndex], nums[right]);               
        return smallIndex;
    }
};