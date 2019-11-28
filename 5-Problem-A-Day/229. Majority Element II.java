class Solution {
    public List<Integer> majorityElement(int[] nums) {
        if (nums == null || nums.length == 0)
            return new LinkedList<>();
        int count1 = 0, count2 = 0, candidate1 = nums[0], candidate2 = nums[0];
        for (int n : nums) {
            if (n == candidate1)
                count1 += 1;
            else if (n == candidate2)
                count2 += 1;
            else if (count1 == 0) {
                candidate1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = n;
                count2 = 1;
            } else {
                count1 -= 1;
                count2 -= 1;
            }
        }
        List<Integer> ans = new LinkedList<>();
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }
        if (count1 > nums.length / 3)
            ans.add(candidate1);
        if (count2 > nums.length / 3)
            ans.add(candidate2);
        return ans;
    }
}
