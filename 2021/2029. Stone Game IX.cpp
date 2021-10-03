class Solution {
public:
    vector<unordered_map<string, bool>> mem;
    bool stoneGameIX(vector<int>& stones) {    
        vector<int> count(3, 0);
        for (int i = 0; i < stones.size(); i++) {            
            count[stones[i] % 3]++;
        }
        count[0] = count[0] % 2 + (count[0] >= 2 ? 2 : 0);
        int dup = min(count[1], count[2]);
        dup = max(0, dup - 2);
        count[1] -= dup; 
        count[2] -= dup;
        mem.resize(2);
        return canWin(count, 0, 0);
    }
    
    bool canWin(vector<int>& count, int sum, int player) {
        sum = sum % 3;
        string key = to_string(count[0]) + "#" + to_string(count[1]) + "#" + to_string(count[2]);
        if (mem[player].find(key) != mem[player].end()) {
            return mem[player][key];
        }       
        int total = 0;
        for (int i = 0; i < 3; i++) {
            total += count[i];
            if (count[i] > 0 && (sum + i) % 3 != 0) {
                count[i]--;
                if (!canWin(count, sum + i, 1 - player)) {
                    count[i]++;
                    mem[player][key] = true;
                    return true;
                }
                count[i]++;
            }            
        }            
        mem[player][key] = player == 1 ? total == 0 : false;
        return mem[player][key];        
    }
    
    
};