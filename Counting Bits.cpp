class Solution {
public:
    vector<int> countBits(int num) {
        int count, carry, tmps, sum, last;
        vector<int> res;
        res.push_back(0);
        last = 0;
        for (int i = 0; i < num; i++){
            count = -1;
            carry = 1;
            sum = i;
            while(carry){
                count++;
                tmps = sum;
                sum = tmps ^ carry;
                carry = (tmps & carry) << 1;                                
            }
            last = last + 1 - count;
            res.push_back(last);
        }
        return res;
    }
};