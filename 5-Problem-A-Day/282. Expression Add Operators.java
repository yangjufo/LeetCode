class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> ans = new ArrayList<String>();
        if (num == null || num.length() == 0)
            return ans;
        helper(ans, "", num, target, 0, 0, 0);
        return ans;
    }

    private void helper(List<String> ans, String path, String num, int target, int pos, long eval,
            long multed) {
        if (pos == num.length()) {
            if (target == eval)
                ans.add(path);
        }
        for (int i = pos; i < num.length(); i++) {
            if (i != pos && num.charAt(pos) == '0')
                break;
            long curr = Long.parseLong(num.substring(pos, i + 1));
            if (pos == 0)
                helper(ans, path + curr, num, target, i + 1, curr, curr);
            else {
                helper(ans, path + "+" + curr, num, target, i + 1, eval + curr, curr);
                helper(ans, path + "-" + curr, num, target, i + 1, eval - curr, -curr);
                helper(ans, path + "*" + curr, num, target, i + 1, eval - multed + multed * curr,
                        multed * curr);
            }
        }
    }
}
