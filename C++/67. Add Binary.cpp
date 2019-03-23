class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string res = "";
        int tmp_res;
        while (i > -1 && j > -1){
            tmp_res = a[i] -'0' + b[j] -'0' + carry;
            if (tmp_res == 0){
                carry = 0;
                res = "0" + res;
            }
            else if (tmp_res == 1){            
                carry = 0;
                res = "1" + res;
            }
            else if (tmp_res == 2){
                carry = 1;
                res = "0" + res;
            }
            else{
                carry = 1;
                res = "1" + res;
            }
            i -= 1;
            j -= 1;
        }
        while (i > - 1){
            tmp_res = a[i] - '0' + carry;
            if (tmp_res == 0){
                carry = 0;
                res = "0" + res;
            }
            else if (tmp_res == 1){
                carry = 0;
                res = "1" + res;
            }
            else{
                carry = 1;
                res = "0" + res;
            }
            i--;
        }
        while (j > - 1){
            tmp_res = b[j] - '0' + carry;
            if (tmp_res == 0){
                carry = 0;
                res = "0" + res;
            }
            else if (tmp_res == 1){
                carry = 0;
                res = "1" + res;
            }
            else{
                carry = 1;
                res = "0" + res;
            }
            j--;
        }
        if (carry == 1)
            res = "1" + res;
        return res;
    }
};