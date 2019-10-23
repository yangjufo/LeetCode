class Solution {
    public String convert(String s, int numRows) {
        List[] rows = new List[numRows];
        int count = 0;
        for (int i = 0; i < numRows; i++)
            rows[i] = new ArrayList<>();        
        int flag = 1;
        for (char c : s.toCharArray()) {            
            rows[count].add(c);
            count = (count + flag) % numRows;
            if (count == 0 || count == numRows - 1)
                flag = -flag;
        }   
        String ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < rows[i].size(); j++) {
                ans += rows[i].get(j);
            }
        }
        return ans;
    }
}
