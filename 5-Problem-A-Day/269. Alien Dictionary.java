class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> map = new HashMap<>();
        Map<Character, Integer> degree = new HashMap<>();
        String ans = "";
        if (words == null || words.length == 0)
            return ans;
        for (String s : words) {
            for (char c : s.toCharArray())
                degree.put(c, 0);
        }
        for (int i = 0; i < words.length - 1; i++) {
            String curr = words[i], next = words[i + 1];
            int length = Math.min(curr.length(), next.length());
            for (int j = 0; j < length; j++) {
                char c1 = curr.charAt(j), c2 = next.charAt(j);
                if (c1 != c2) {
                    Set<Character> set = map.getOrDefault(c1, new HashSet<>());
                    if (!set.contains(c2)) {
                        set.add(c2);
                        map.put(c1, set);
                        degree.put(c2, degree.get(c2) + 1);
                    }
                    break;
                }
            }
        }

        Queue<Character> q = new LinkedList<Character>();
        for (char c : degree.keySet()) {
            if (degree.get(c) == 0)
                q.add(c);
        }

        while (!q.isEmpty()) {
            char c = q.remove();
            ans += c;
            if (map.containsKey(c)) {
                for (char c2 : map.get(c)) {
                    degree.put(c2, degree.get(c2) - 1);
                    if (degree.get(c2) == 0)
                        q.add(c2);
                }
            }
        }

        if (ans.length() != degree.size())
            return "";
        return ans;

    }
}
