class Solution {
    public boolean isHappy(int n) {
        Set<Integer> nums = new HashSet<>();
        int ans = 1;
        while (!nums.contains(ans)) {
            nums.add(ans);
            ans = loop(n);
            n = ans;
        }
        return ans == 1;
    }
    
    private int loop(int n) {
        int ans = 0;
        while (n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
}