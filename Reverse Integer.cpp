class Solution {
public:
    int reverse(int x) {
        bool flag = x < 0;
        int res;        
        if (flag)
            x = -x;
        if (x < 0)
            return 0;              
        res = 0;
        while(x > 0){       
            if (x < 10) {
               if ((INT_MAX - x) * 1.0 / 10 < res)
                    return 0;
            }
            res = res * 10 + x % 10;   
            x /= 10;
        }
        if (flag)
            res = -res;        
        return res;                    
    }
};