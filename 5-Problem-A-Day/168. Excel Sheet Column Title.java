class Solution {
    public String convertToTitle(int n) {
        StringBuilder ans = new StringBuilder();
        while (n > 0) {
            int last = n % 26 == 0 ? 26 : n % 26;
            ans.append(Character.toString((char) (64 + last)));
            n = (n - last) / 26;
        }
        ans.reverse();
        return ans.toString();
    }
}
