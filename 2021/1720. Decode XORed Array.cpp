class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans {first};    
        for (int i = 0; i < encoded.size(); i++) {
            ans.push_back(first ^ encoded[i]);
            first = ans.back();
        }
        return ans;
    }
};