class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
        sort(clips.begin(), clips.end(), [](vector<int>& left, vector<int>& right) {
           if (left[0] == right[0])
               return left[1] < right[1];
            return left[0] < right[0];
        });        
        if (clips[0][0] != 0 || clips.back()[1] < T) return -1;
        vector<vector<int>> needed;
        for (vector<int> c : clips) {
            if (needed.empty())
                needed.push_back(c);            
            else if (c[0] > needed.back()[1]) return -1;
            else {                
                int i = 0;
                for (; i < needed.size(); i++) {
                    if (c[0] <= needed[i][1] && c[1] > needed.back()[1])
                        break;
                }
                if (needed.size() > i) {                      
                    while (needed.size() > i + 1)
                        needed.pop_back();
                    if (c[0] == needed[i][0])
                        needed.pop_back();
                    needed.push_back(c);
                }                
            }
            // for (vector<int> n : needed) {
            //     cout << "["  << n[0] << "," << n[1] << "]"<<",";
            // }
            // cout << endl;
            if (needed.back()[1] >= T)
                break;
        }        
        return needed.size();
    }
};