class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {        
        unordered_map<string, int> index1;
        int minSum = list1.size() + list2.size();
        vector<string> res;
        for (int i = 0; i < list1.size(); i++) {
            index1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (index1.find(list2[i]) != index1.end()) {
                if (i + index1[list2[i]] <= minSum) {
                    if (i + index1[list2[i]] < minSum) {
                        res.clear();
                    }                    
                    minSum = i + index1[list2[i]];
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};