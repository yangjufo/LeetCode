class Solution {
    List<List<String>> ans;
    ArrayList<String> curr;

    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        curr = new ArrayList<>();
        backtrack(s, 0);
        return ans;
    }

    private void backtrack(String s, int l) {
        if (curr.size() > 0 && l >= s.length())
            ans.add(new ArrayList<String>(curr));
        for (int i = l; i < s.length(); i++) {
            if (isPalindrome(s, l, i)) {
                if (l == i)
                    curr.add(Character.toString(s.charAt(i)));
                else
                    curr.add(s.substring(l, i + 1));
                backtrack(s, i + 1);
                curr.remove(curr.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String str, int l, int r) {
        while (l < r) {
            if (str.charAt(l) != str.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}
