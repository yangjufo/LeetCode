class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<string, long long> dp;
    unordered_map<string, unordered_map<string, long long>> mem;
    int colorTheGrid(int m, int n) {
        string curr;
        getStart(curr, m);        
        curr.clear();
        for (auto& iter : dp) {
            dfs(curr, m, iter.first);
        }        
        for (int i = 1; i < n; i++) {
            unordered_map<string, long long> next;
            for (auto& iter : dp) {
                next[iter.first] = 0;
                for (auto& mi : mem[iter.first]) {
                    next[iter.first] = (next[iter.first] + mi.second * dp[mi.first]) % mod;
                }
            }
            dp = next;
        }
        int count = 0;
        for (auto& iter : dp) {
            count = (count + iter.second) % mod;
        }
        return count;
    }
    
    void dfs(string& curr, int m, string parent) {
        if (curr.size() >= m) {
            mem[getKey(curr)][parent] += 1;
            return;
        }        
        for (char c = '0'; c <= '2'; c++) {
            if ((curr.empty() || c != curr.back()) && (parent[curr.size()] != c)) {
                curr += c;
                dfs(curr, m, parent);
                curr.pop_back();
            }
        }
    }
    
    void getStart(string& curr, int m) {
        if (curr.size() >= m) {
            dp[getKey(curr)]++;
            return;
        }        
        for (char c = 'a'; c <= 'c'; c++) {
            if (curr.empty() || c != curr.back()) {
                curr += c;
                getStart(curr, m);
                curr.pop_back();
            }
        }
    }    
    
    string getKey(string& curr) {
        int index = 0;
        unordered_map<char, int> re;
        string key;
        for (char c : curr) {
            if (re.find(c) == re.end()) {
                re[c] = index;
                index++;
            }
            key += re[c] + '0';
        }
        return key;
    }
};