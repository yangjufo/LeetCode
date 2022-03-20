class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res(queryIndices.size(), 0);
        map<int, int> lenCount, posMap;
        int start = 0;

        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] != s[start]) {
                lenCount[i - start]++;
                posMap[start] = i - 1;
                start = i;
            }
        }

        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];

            if (s[index] != queryCharacters[i]) {
                s[index] = queryCharacters[i];

                auto iter = posMap.lower_bound(index);
                if (iter == posMap.end() || iter->first > index) {
                    iter = prev(iter);
                }

                removeLen(lenCount, iter->second - iter->first + 1);

                vector<pair<int, int>> cand;
                if (iter->first < index) {
                    cand.push_back({iter->first, index - 1});
                }
                if (iter->second > index) {
                    cand.push_back({index + 1, iter->second});
                }

                if (iter->first == index && iter->second == index && index > 0 && s[prev(iter)->first] == s[index] && index + 1 < s.length() && s[next(iter)->first] == s[index]) {
                    removeLen(lenCount, prev(iter)->second - prev(iter)->first + 1);
                    removeLen(lenCount, next(iter)->second - next(iter)->first + 1);
                    cand.push_back({prev(iter)->first, next(iter)->second});
                    posMap.erase(prev(iter));
                    posMap.erase(next(iter));
                } else if (iter->first == index && iter->first > 0 && s[prev(iter)->first] == s[index]) {
                    removeLen(lenCount, prev(iter)->second - prev(iter)->first + 1);
                    posMap[prev(iter)->first] = index;
                    lenCount[index - prev(iter)->first + 1]++;
                } else if (iter->second == index && iter->second + 1 < s.length() && s[next(iter)->first] == s[index]) {
                    removeLen(lenCount, next(iter)->second - next(iter)->first + 1);
                    cand.push_back({index, next(iter)->second});
                    posMap.erase(next(iter));
                } else {
                    cand.push_back({index, index});
                }

                posMap.erase(iter);

                for (auto& it : cand) {
                    posMap[it.first] = it.second;
                    lenCount[it.second - it.first + 1]++;
                }
            }

            res[i] = lenCount.rbegin()->first;
        }
        return res;
    }

    void removeLen(map<int, int>& lenCount, int oldLen) {
        lenCount[oldLen]--;
        if (lenCount[oldLen] == 0) {
            lenCount.erase(oldLen);
        }
    }
};