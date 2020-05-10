class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ops = new ArrayList<>();
        int index = 0;
        for (int i = 1; i <= n && index < target.length; i++) {
            if (target[index] == i) {
                ops.add("Push");
                index += 1;
                continue;
            }
            ops.add("Push");
            ops.add("Pop");
        }
        return ops;
    }
}