class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> sCount;
        for (char c : S) {
            sCount[c]++;         
            if (sCount[c] > (S.length() + 1) / 2) return "";
        }
        
        auto Comparator = [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(Comparator)> pq(Comparator);
        for (auto& iter : sCount) {
            pq.push({iter.first, iter.second});
        }
                
        string ans;
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if (ans.empty() || first.first != ans.back()) {
                ans += first.first;                                
                if (first.second > 1) {
                    pq.push({first.first, first.second - 1});
                }
            } else {
                auto second = pq.top();
                pq.pop();
                ans += second.first;                
                if (second.second > 1) {
                    pq.push({second.first, second.second - 1});
                }
                pq.push({first.first, first.second});                
            }
        }
        return ans;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> sCount(26, 0);
        int maxIndex = 0;
        for (char c : S) {
            sCount[c - 'a']++;
            if (sCount[c - 'a'] > sCount[maxIndex]) {
                maxIndex = c - 'a';
            }
        }
        
         if (sCount[maxIndex] > (S.length() + 1) / 2) {
            return ""; 
        }
        
        string ans = S;
        int index = 0;
        while (sCount[maxIndex] > 0) {
            ans[index] = maxIndex + 'a';
            index += 2;
            sCount[maxIndex]--;
        }
        
        for (int i = 0; i < 26; i++) {
            while (sCount[i] > 0) {
                if (index >= ans.length()) index = 1;
                ans[index] = i + 'a';
                index += 2;
                sCount[i]--;
            }
        }
        
        return ans;
    }
};