class Solution {
    public int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int tmp = x % 10;                        
            if ((ans > 0 && ans > (Integer.MAX_VALUE - tmp) / 10) || (ans < 0 && ans < (Integer.MIN_VALUE - tmp) / 10))
                return 0;
            ans = ans * 10 + tmp;
            x /= 10;
        }
        return ans;
    }
}
