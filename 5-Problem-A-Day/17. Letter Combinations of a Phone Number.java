class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        List<String> curr = new ArrayList<>();
        String[][] nums = {{}, {}, {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"},
                {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"},
                {"w", "x", "y", "z"}};
        for (int i = 0; i < digits.length(); i++) {
            int d = Character.getNumericValue(digits.charAt(i));
            if (ans.size() == 0) {
                for (String n : nums[d])
                    ans.add(n);
            } else {
                for (String a : ans) {
                    for (String n : nums[d])
                        curr.add(a + n);
                }
                ans = new ArrayList<>(curr);
                curr = new ArrayList<>();
            }
        }
        return ans;
    }
}
