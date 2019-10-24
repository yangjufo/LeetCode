class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        StringBuilder ans = new StringBuilder();
        boolean diff = false;
        int index = 0;
        while (!diff && index < strs[0].length()) {
            char c = strs[0].charAt(index);
            for (int i = 1; i < strs.length; i++) {
                if (index >= strs[i].length() || strs[i].charAt(index) != c) {
                    diff = true;
                    break;
                }
            }
            if (!diff)
                ans.append(c);
            index += 1;
        }
        return ans.toString();
    }
}
