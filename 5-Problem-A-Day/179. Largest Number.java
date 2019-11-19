class Solution {
    public String largestNumber(int[] nums) {
        String[] strs = Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
        Arrays.sort(strs, (a, b) -> (b + a).compareTo(a + b));
        return strs[0].equals("0") ? "0" : String.join("", strs);
    }
}
