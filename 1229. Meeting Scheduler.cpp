class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            while (i < slots1.size() && slots1[i][1] - slots1[i][0] < duration) i++;
            while (j < slots2.size() && slots2[j][1] - slots2[j][0] < duration) j++;
            if (i < slots1.size() && j < slots2.size()) {
                if (slots1[i][0] <= slots2[j][0]) {
                    if(slots2[j][0] + duration <= slots1[i][1]) {
                        return {slots2[j][0], slots2[j][0] + duration};
                    }                        
                    else {
                        i++;
                    }
                } else {
                    if (slots1[i][0] + duration <= slots2[j][1]) {
                        return {slots1[i][0], slots1[i][0] + duration};
                    }
                    else {
                        j++;
                    }
                }                
            }
        }
        return {};
    }
};
