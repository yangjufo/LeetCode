class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        vector<pair<char, int>> freq;
        for (auto iter : counts) {
            freq.push_back(iter);
        }
        sort(freq.begin(), freq.end(), [](pair<char, int> left, pair<char, int> right){
            return left.second > right.second;
        });
        string res;
        for (pair<char, int> f : freq) {
            res += string(f.second, f.first);
        }
        return res;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        int maxFreq = 0;
        for (auto &iter : counts) {
            maxFreq = max(maxFreq, iter.second);
        }
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto &iter : counts) {
            buckets[iter.second].push_back(iter.first);
        }
        
        string res;
        for (int i = maxFreq; i > 0; i--) {
            for (char c : buckets[i]) {
                res += string(i, c);
            }
        }
        return res;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        vector<pair<int, int>> countPair;
        for (auto iter : count) {
            countPair.push_back({iter.second, iter.first});
        }
        sort(countPair.begin(), countPair.end());
        string res;        
        for (int i = (int)countPair.size() - 1; i >= 0; i--) {            
            res += string(countPair[i].first, countPair[i].second);
        }
        return res;
    }
};