class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> count = new HashMap<>();
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (count.containsKey(c))
                count.put(c, count.get(c) + 1);
            else
                count.put(c, 1);
            if (count.get(c) > 1) {
                while (start <= i && count.get(c) > 1) {
                    count.put(s.charAt(start), count.get(s.charAt(start)) - 1);
                    start++;
                }
            }            
            maxLen = Math.max(maxLen, i - start + 1);
        }        
        return maxLen;
    }
}