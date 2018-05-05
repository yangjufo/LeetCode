class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int start, mid, end;
        start = 1;
        end = x;
        while (true){
            mid = (start + end) / 2;            
            if(mid > x / mid){
                end = mid - 1;
            }
            else {
                if ((mid + 1) > x / (mid + 1))
                    return mid;
                start = mid + 1;
            }
        }
    }
};