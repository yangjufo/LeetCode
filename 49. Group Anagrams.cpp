class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> ana_map;
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end(), [](char c1, char c2){ return c1 < c2; });
            if (ana_map.count(tmp) != 0){
                res[ana_map[tmp]].push_back(str);
            }
            else{
                res.push_back(vector<string>{str});
                ana_map.insert(pair<string, int>(tmp, res.size() - 1));
            }
        }
        return res;
    }
};