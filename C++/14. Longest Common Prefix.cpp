class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";        
        char tmp;
        int count = 0;
        int length = strs.size();
        if (length == 0)
            return res;
        if (length == 1)
            return strs[0];
        if (strs[0].length() == 0)
            return res;
        else
            tmp = strs[0][0];        
        for(int i = 1; i < length; i++){            
            if (strs[i].length() == count)
                return res;
            if (strs[i][count] != tmp)
                return res;
            if (i == length - 1){
                res += tmp;
                count++;
                if (strs[0].length() == count)
                    return res;
                else                    
                    tmp = strs[0][count];
                i = 0;
            }                
        }
        return res;
    }    
};