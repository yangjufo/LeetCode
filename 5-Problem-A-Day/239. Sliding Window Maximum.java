class Solution {
    ArrayDeque<Integer> deq = new ArrayDeque<Integer>();
    int[] nums;

    private void cleanDeque(int i, int k) {
        if (!deq.isEmpty() && deq.getFirst() == i - k)
            deq.removeFirst();
        while (!deq.isEmpty() && nums[i] > nums[deq.getLast()])
            deq.removeLast();
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n * k == 0)
            return new int[0];
        if (k == 1)
            return nums;

        this.nums = nums;
        int max_idx = 0;
        for (int i = 0; i < k; i++) {
            cleanDeque(i, k);
            deq.addLast(i);
            if (nums[i] > nums[max_idx])
                max_idx = i;
        }

        int[] ans = new int[n - k + 1];
        ans[0] = nums[max_idx];
        for (int i = k; i < n; i++) {
            cleanDeque(i, k);
            deq.addLast(i);
            ans[i - k + 1] = nums[deq.getFirst()];
        }

        return ans;

    }
}
