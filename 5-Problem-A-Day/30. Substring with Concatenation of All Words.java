class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new LinkedList<>();
        if (words.length == 0 || s.length() < words.length * words[0].length())
            return ans;
        int N = s.length(), M = words.length, K = words[0].length();
        Map<String, Integer> map = new HashMap<>(), curMap = new HashMap<>();
        for (String ls : words)
            map.put(ls, map.getOrDefault(ls, 0) + 1);
        String str = null, tmp = null;
        for (int i = 0; i < K; i++) {
            int count = 0;
            for (int l = i, r = i; r + K <= N; r += K) {
                str = s.substring(r, r + K);
                if (map.containsKey(str)) {
                    curMap.put(str, curMap.getOrDefault(str, 0) + 1);
                    if (curMap.get(str) <= map.get(str))
                        count += 1;
                    while (curMap.get(str) > map.get(str)) {
                        tmp = s.substring(l, l + K);
                        curMap.put(tmp, curMap.get(tmp) - 1);
                        l += K;
                        if (curMap.get(tmp) < map.get(tmp))
                            count -= 1;
                    }
                    if (count == M) {
                        ans.add(l);
                        tmp = s.substring(l, l + K);
                        curMap.put(tmp, curMap.get(tmp) - 1);
                        l += K;
                        count -= 1;
                    }
                } else {
                    curMap.clear();
                    count = 0;
                    l = r + K;
                }
            }
            curMap.clear();
        }
        return ans;
    }
}
