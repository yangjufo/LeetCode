class Solution {
    public int minimumKeypresses(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            count.put(s.charAt(i), count.getOrDefault(s.charAt(i), 0) + 1);
        }
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(count.entrySet());
        list.sort(Map.Entry.comparingByValue());
        int ans = 0;
        for (int i = list.size() - 1; i >= 0; i--) {
            ans += list.get(i).getValue() * ((list.size() - i - 1) / 9 + 1);
        }
        return ans;
    }
}