class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<pair<char, vector<int>>> counter(26, {'#', vector<int>(26, 0)});
        
        for (string v : votes) {
            for (int i = 0; i < v.length(); i++) {
                counter[v[i] - 'A'].first = v[i];
                counter[v[i] - 'A'].second[i]++;
            }
        }           
        
        sort(counter.begin(), counter.end(), [](pair<char, vector<int>>& left, pair<char, vector<int>>& right) {
            for (int i = 0; i < 26; i++) {
                if ((left.second)[i] != (right.second)[i]) {
                    return (left.second)[i] > (right.second)[i];
                }
            }
            return left.first < right.first;
        });       
        
        string res;
        for (int i = 0; i < counter.size() && counter[i].first != '#'; i++) {
            res += counter[i].first;
        }
        return res;
    }
};