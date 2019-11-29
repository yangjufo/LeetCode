class WordDistance {

    Map<String, List<Integer>> locations;

    public WordDistance(String[] words) {
        locations = new HashMap<String, List<Integer>>();
        for (int i = 0; i < words.length; i++) {
            List<Integer> loc = locations.getOrDefault(words[i], new ArrayList<Integer>());
            loc.add(i);
            locations.put(words[i], loc);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> loc1 = locations.get(word1), loc2 = locations.get(word2);
        int l1 = 0, l2 = 0, minDiff = Integer.MAX_VALUE;
        while (l1 < loc1.size() && l2 < loc2.size()) {
            minDiff = Math.min(minDiff, Math.abs(loc1.get(l1) - loc2.get(l2)));
            if (loc1.get(l1) < loc2.get(l2))
                l1++;
            else
                l2++;
        }
        return minDiff;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such: WordDistance obj = new
 * WordDistance(words); int param_1 = obj.shortest(word1,word2);
 */
