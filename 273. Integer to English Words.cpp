class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        int num_base[] = {1000000000, 1000000, 1000, 100};
        string base_bits[] = {"Billion", "Million", "Thousand", "Hundred"};
        string one_bit[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string two_bits[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens_bits[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string res = "";
        if (num >= num_base[0]){
            res += numberToWords(num / num_base[0]) + " "  + base_bits[0]; 
        }
        num = num % num_base[0];
        if (num >= num_base[1]){
            res += " " + numberToWords(num / num_base[1]) + " " + base_bits[1];
        }
        num = num % num_base[1];
        if (num >= num_base[2]){
            res += " " + numberToWords(num / num_base[2]) + " " + base_bits[2];
        }
        num = num % num_base[2];
        if (num >= num_base[3]){
            res += " " + numberToWords(num / num_base[3]) + " " + base_bits[3];
        }
        num = num % num_base[3];
        int tmp = num / 10;
        if (tmp >= 2){
            res += " " + tens_bits[tmp - 2];
            tmp = num % 10;
            res += tmp == 0 ? "" : " " + one_bit[tmp];
        }
        else if (tmp == 1){
            res += " " + two_bits[num % 10];
        }
        else{
            
            res += num == 0 ? "" : " " + one_bit[num];
        }
        
        return res[0] == ' ' ? res.substr(1, res.length() -1) : res;                    
    }
};