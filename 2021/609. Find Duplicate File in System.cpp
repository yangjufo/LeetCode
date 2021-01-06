class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentPathMap;
        for (string path : paths) {
            int i = 0;            
            string directory;
            while (path[i] != ' ') {
                directory += path[i];
                i++;
            }
            i++;
            string name, content;
            string tmp;
            while (i < path.length()) {               
                if (path[i] == '(') {
                    name = tmp;
                    tmp = "";
                } else if (path[i] == ')') {
                    content = tmp;                    
                    contentPathMap[content].push_back(directory+ "/" + name);
                    content = "";
                    tmp = "";
                } else if (path[i] != ' ') {
                    tmp += path[i];
                }                
                i++;
            }                        
        }        
        vector<vector<string>> ans;
        for (auto& iter : contentPathMap) {
            if (iter.second.size() >= 2) {
                ans.push_back(iter.second);
            }
        }
        return ans;
    }
};