class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s, wordDict, new HashMap<String, LinkedList<String>>());
        
    }
    List<String> dfs(String s, List<String> wordDict, HashMap<String, LinkedList<String>> map) {
        if (map.containsKey(s)) 
            return map.get(s);
        
        LinkedList<String> res = new LinkedList<String>();
        if (s.length() == 0) {
            res.add("");
            return res;
        }
        for (int i =0; i< wordDict.size(); i++) {
            String word = wordDict.get(i);
            if (s.startsWith(word)) {
                List<String> sublist = dfs(s.substring(word.length()), wordDict, map);
                for (String sub: sublist) 
                    res.add(word + (sub.isEmpty() ? "": " ") + sub); 
            }
        }
        map.put(s, res);
        return res;
    }
}
