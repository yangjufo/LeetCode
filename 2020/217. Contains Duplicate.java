class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> appears = new HashSet<>();
        for (int n : nums) {
            if (appears.contains(n))
                return true;
            appears.add(n);
        }
        return false;
    }
}
