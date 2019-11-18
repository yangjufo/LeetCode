class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character, Integer> ch = new HashMap<>();
        int start = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            ch.put(c, ch.getOrDefault(c, 0) + 1);
            while (ch.size() > 2) {
                int count = ch.get(s.charAt(start));
                if (count == 1)
                    ch.remove(s.charAt(start));
                else
                    ch.put(s.charAt(start), count - 1);
                start++;
            }            
            ans = Math.max(ans, i - start + 1);
        }
        return ans;
    }
}