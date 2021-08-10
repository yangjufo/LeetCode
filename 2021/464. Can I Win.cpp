class Solution {
public:    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {    
        if ((1 + maxChoosableInteger) * maxChoosableInteger  < desiredTotal * 2) {
            return false;
        }            
        unordered_map<int, bool> mem;
        return canWin(mem, desiredTotal, 0, maxChoosableInteger);
    }
    
    bool canWin(unordered_map<int, bool>& mem, int desiredTotal, int state, int maxInt) {
        if (mem.find(state) != mem.end()) return mem[state];              
        mem[state] = false;
        for (int i = maxInt; i >= 1; i--) {
            if ((state & (1 << i)) == 0) {
                if (i >= desiredTotal || !canWin(mem, desiredTotal - i, (state | (1 << i)), maxInt)) {
                    mem[state] = true;
                    break;
                }
            }
        }
        return mem[state];
    }
};