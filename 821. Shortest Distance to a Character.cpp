class Solution {
public:
    vector<int> shortestToChar(string S, char C) {       
        vector<int> res;
        if (S.length() == 0)
            return res;
        vector<int> charPos;
        int length = S.length();
        for (int i = 0; i < length; i++){
            if (S[i] == C)
                charPos.push_back(i);
        }
        int charLength = charPos.size();
        for (int i = 0; i < length; i++){
            int min = length;
            for (int j = 0; j < charLength; j++){
                int tmp = abs(i - charPos[j]);
                if (tmp < min)                    
                    min = tmp;
            }
            res.push_back(min);
        }            
        return res;
    }
};