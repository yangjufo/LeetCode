class Solution {
    public int minDeletions(String s) {
        int[] counts = new int[26];
        for (char c : s.toCharArray()) {
            counts[c - 'a'] += 1;
        }
        Arrays.sort(counts);
        int ans = 0;
        for (int i = 25; i > 0; i--) {
            if (counts[i] <= counts[i - 1] && counts[i - 1] > 0) {
                int diff = counts[i] == 0 ? counts[i - 1] : counts[i - 1] - counts[i] + 1;
                counts[i - 1] -= diff;
                ans += diff;
            }
        }
        return ans;
    }
}