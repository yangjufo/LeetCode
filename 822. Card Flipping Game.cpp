class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        if (fronts.empty())
            return 0;
        int length = fronts.size();
        vector<int> flipPos;
        vector<int> sameNum;
        for (int i = 0; i < length; i++){
            if (fronts[i] != backs[i])
                flipPos.push_back(i);            
            else
                sameNum.push_back(fronts[i]);
        }       
        int min = INT_MAX;
        for (int i = 0; i < flipPos.size(); i++){
            int tmp_f = fronts[flipPos[i]];
            int tmp_b = backs[flipPos[i]];
            bool fl = false;
            bool fb = false;
            for (int j = 0; j < sameNum.size(); j++){
                if (tmp_f == sameNum[j])
                    fl = true;
                if (tmp_b == sameNum[j])
                    fb = true;
                if (fb && fl)
                    break;            
            }
            if (!fl && tmp_f < min)
                min = tmp_f;
            if (!fb && tmp_b < min)
                min = tmp_b;
            
        }
        return min == INT_MAX ? 0 : min;
    }
};