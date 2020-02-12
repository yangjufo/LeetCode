class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;
        int[] masks = new int[n];
        int[] lens = new int[n];
        
        int bitmask = 0;
        for (int i = 0; i < n; i++) {
            bitmask = 0;
            for (char ch: words[i].toCharArray()) {
                bitmask |= 1 << (int)(ch - 'a');
            }
            masks[i] = bitmask;
            lens[i] = words[i].length();
        }
        
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0)
                    maxVal = Math.max(maxVal, lens[i] * lens[j]);
            }
        }
        
        return maxVal;
    }
}