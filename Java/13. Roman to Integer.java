class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> numbers = new HashMap<Character, Integer>() {
            {
                put('I', 1);
                put('V', 5);
                put('X', 10);
                put('L', 50);
                put('C', 100);
                put('D', 500);
                put('M', 1000);
            }            
        };
        int res = 0, flag = 1;
        for (int i = 0; i < s.length(); i++) {
            flag = 1;
            if (i < s.length() -1 && numbers.get(s.charAt(i)) < numbers.get(s.charAt(i + 1)))
                flag = -1;
            res += flag * numbers.get(s.charAt(i));
        }
        return res;
    }
}