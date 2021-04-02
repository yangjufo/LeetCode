class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sCount;
        for (int i = 0; i + 10 <= s.length(); i++) {
            sCount[s.substr(i, 10)]++;
        }
        vector<string> res;
        for (auto& iter : sCount) {
            if (iter.second > 1) {
                res.push_back(iter.first);
            }
        }
        return res;
    }
};

class Solution {
public:
    unordered_map<char, int> cMap = 
    {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}  
    };
    vector<string> findRepeatedDnaSequences(string s) {
        int L = 10, n = s.length();
        if (n <= L) return {};
        
        int a = 4, aL =(int)pow(a, L);
        int* nums = new int[n];
        for(int i = 0; i < n; i++) {
            nums[i] = cMap[s[i]];
        }
        
        int h = 0;
        unordered_set<int> seen;
        unordered_set<string> output;
        for (int i = 0; i < n - L + 1; i++) {
            if (i != 0) {
                h = h * a - nums[i - 1] * aL + nums[i + L - 1];                
            } else {
                for (int j = 0; j < L; j++) {
                    h = h * a + nums[j];
                }
            }
            if (seen.find(h) != seen.end()) {
                output.insert(s.substr(i, L));
            }
            seen.insert(h);
        }        
        return vector<string>(output.begin(), output.end());
    }
};