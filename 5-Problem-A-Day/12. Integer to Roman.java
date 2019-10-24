class Solution {
    public String intToRoman(int num) {
        int[] integers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder ans = new StringBuilder();        
        while (num > 0) {                  
            for (int i = 0; i < integers.length; i++) {                
                while (num >= integers[i]) {
                    ans.append(romans[i]);                        
                    num -= integers[i];
                }                                    
            }                        
        }
        return ans.toString();
    }
}