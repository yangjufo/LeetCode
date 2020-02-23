class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> count = new HashMap<>();
        int start = 0, ans = 0, total = 0;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (!count.containsKey(chars[i]) || count.get(chars[i]) == 0) {
                count.put(chars[i], 1);
                total += 1;
            } else
                count.put(chars[i], count.get(chars[i]) + 1);
            while (total > k) {
                count.put(chars[start], count.get(chars[start]) - 1);
                if (count.get(chars[start]) == 0)
                    total -= 1;
                start += 1;
            }
            ans = Math.max(ans, i - start + 1);
        }
        return ans;
    }
}
