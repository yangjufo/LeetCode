class Solution {
    public List<List<Integer>> generate(int numRows) {
        LinkedList<List<Integer>> ans = new LinkedList<>();
        if (numRows >= 1)
            ans.add(Arrays.asList(1));
        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new LinkedList<>(Arrays.asList(1));
            List<Integer> last = ans.getLast();
            for (int j = 0; j < last.size() - 1; j++)
                row.add(last.get(j) + last.get(j + 1));
            row.add(1);
            ans.add(row);
        }
        return ans;
    }
}
