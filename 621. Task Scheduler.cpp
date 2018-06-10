class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty())
            return 0;
        map<char, int> task_count;
        map<int, vector<char>> task_sort;    
        int min_count = 0;        
        int i = 1;
        for (auto ch : tasks){
            if (task_count.count(ch) == 0){
                task_count[ch] = 1;                
            }
            else{
                task_count[ch] += 1;
            }     
            task_sort[i] = vector<char>{};
            i++;
        }
        for (auto val : task_count){            
            task_sort[val.second].push_back(val.first);
        }       
        int tmp_count;        
        for (i = tasks.size(); i > 0; i--){
            if (!task_sort[i].empty()){
                tmp_count = (i - 1) * n;
                min_count += tmp_count + i;                
                for (int j = 1; j < task_sort[i].size(); j++){                    
                    min_count += 1;                    
                    tmp_count -= i - 1;
                }                
                break;
            }
        }       
        i -= 1;        
        for (; i > 0; i--){                                                    
            if (!task_sort[i].empty()){                
                for (int j = 0; j < task_sort[i].size(); j++){                    
                    tmp_count -= i;
                }
            }
        }        
        tmp_count = tmp_count > 0 ? 0 : -tmp_count;
        return min_count + tmp_count;
    }
};