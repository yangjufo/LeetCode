class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;
        while (left < right) {
            int tmp = numbers[left] + numbers[right];
            if (tmp == target)
                return new int[] {left + 1, right + 1};
            if (tmp < target)
                left++;
            else
                right--;
        }
        return new int[] {0, 0};
    }}

nclass Solution{

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
