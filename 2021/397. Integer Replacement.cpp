class Solution {
public:
    unordered_map<long, int> mem;
    int integerReplacement(int n) {
        mem[1] = 0;
        mem[2147483647] = 32;
        return dfs(n);
    }
    
    int dfs(long n) {
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        int steps = 0;                
        int curr = n;
        while ((curr & 0x1) == 0 && curr > 1) {
            steps++;
            curr >>= 1;
        }            
        if (curr != 1) {
            steps += 1 + min(dfs(curr + 1), dfs(curr - 1));
        }        
        mem[n] = steps;
        return mem[n];
    }
};