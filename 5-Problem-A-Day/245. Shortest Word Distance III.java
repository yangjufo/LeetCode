class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int i1 = -1, i2 = -1, min = words.length;
        boolean update1 = true;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1) && (update1 || !words[i].equals(word2))) {
                i1 = i;
                update1 = false;
            } else if (words[i].equals(word2) && (!update1 || !words[i].equals(word1))) {
                i2 = i;
                update1 = true;
            }
            if (i1 != -1 && i2 != -1 && i1 != i2)
                min = Math.min(min, Math.abs(i1 - i2));
        }
        return min;
    }
}
