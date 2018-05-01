class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        string tmp;
        string res = "1";
        int i, j, count;
        i = 1;
        while (i < n){
            j = 0;
            tmp = res;   
            res = "";
            while (j < tmp.length()){
                count = 0;
                char tmpc = tmp[j];                
                while (tmp[j] == tmpc){
                    count++;
                    j++;
                }
                res += to_string(count) + tmpc;
            }                     
            i++;
        }
        return res;
    }
};
