class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5, count10;
        count5 = count10 = 0;
        for (int b : bills) {
            if (b == 5) {
                count5++;
            } else if (b == 10) {
                if (count5 == 0) {
                    return false;
                }
                count5--;
                count10++;
            } else if (b == 20) {
                if (count10 == 0) {
                    if (count5 < 3) {
                        return false;
                    }
                    count5 -= 3;
                } else {
                    if (count5 == 0) {
                        return false;
                    }
                    count10 -= 1;
                    count5 -= 1;
                }                    
            }
        }
        return true;
    }
};