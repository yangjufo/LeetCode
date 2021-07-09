class Solution {
public:
    int count = 0;
    int countNumbersWithUniqueDigits(int n) {
        backtrack((int)pow(10, n), 0, 0);
        return count;
    }
    
    void backtrack(int maxNum, int mask, int currNum) {        
        if (currNum >= maxNum) return;
        count++;
        for (int i = 0; i <= 9; i++) {
            if (currNum == 0 && i == 0) continue;
            if ((mask & (1 << i)) == 0) {
                backtrack(maxNum, mask | (1 << i), currNum * 10 + i);
            }            
        } 
    }
}

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)     return 1;
        
        int res = 10;
        int uniqueDigits = 9;
        int availableNumber = 9;
        while (n-- > 1 && availableNumber > 0) {
            uniqueDigits = uniqueDigits * availableNumber;
            res += uniqueDigits;
            availableNumber--;
        }
        return res;
    }
    
};