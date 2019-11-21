class Solution {
    public List<String> findRepeatedDnaSequences(String s) {        
        if (s.length() < 10) return new LinkedList<String>();
        
        Set<String> tens = new HashSet<>(), ans = new HashSet<>();
        for (int i = 10; i <= s.length(); i++) {
            String sub = s.substring(i - 10, i);
            if (tens.contains(sub)) ans.add(sub);
            else tens.add(sub);
        }
        return new LinkedList<String>(ans);
    }
}