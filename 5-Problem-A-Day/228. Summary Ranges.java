class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new LinkedList<>();
        if (nums.length == 0)
            return ans;
        int start = nums[0], last = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - last != 1) {
                if (last == start)
                    ans.add(Integer.toString(start));
                else
                    ans.add(Integer.toString(start) + "->" + Integer.toString(last));
                start = last = nums[i];
            } else
                last = nums[i];
        }
        if (last == start)
            ans.add(Integer.toString(start));
        else
            ans.add(Integer.toString(start) + "->" + Integer.toString(last));
        return ans;
    }
}
