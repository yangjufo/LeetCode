class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res;  
        if (logs.empty()){
            return res;
        }
        vector<int> ids;
        res.resize(n, 0);             
        int id, time;
        bool start, last_start;
        int last_id, last_time;        
        splitStr(logs[0], id, start, time);
        last_id = id;
        last_time = time;
        last_start = start;
        ids.push_back(id);
        for (int i = 1; i < logs.size(); i++){
            splitStr(logs[i], id, start, time);    
            if (start && last_start){
                res[last_id] += time - last_time;
                last_id = id;
                last_time = time;                           
                ids.push_back(id);
            }
            else if (start && !last_start){                
                if (!ids.empty()){
                    res[ids.back()] += time - last_time - 1;
                }
                last_start = start;
                last_id = id;
                last_time = time;
                ids.push_back(id);
            }
            else if (!start){
                res[id] += time - last_time + (last_start ? 1 : 0);                
                last_start = start;                                
                last_time = time;
                ids.pop_back();
            }             
        }            
        return res;
    }
    void splitStr(string s, int& id, bool& start, int& time){        
        id = atoi(strtok((char*)s.c_str(), ":"));        
        start = strcmp(strtok(NULL, ":"), "start") == 0;                
        time = atoi(strtok(NULL, ":"));        
    }
};