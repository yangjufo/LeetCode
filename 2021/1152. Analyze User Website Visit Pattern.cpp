class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> visits;
        unordered_map<string, int> count;
        for (int i = 0; i < username.size(); i++) {
            visits[username[i]][timestamp[i]] = website[i];
        }
        for (auto visits : visits) {
            auto v = visits.second;
            unordered_set<string> userSeqs;
            for (auto it = v.begin(); it != v.end(); it++) {
                for (auto it1 = next(it); it1 != v.end(); it1++) {
                    for (auto it2 = next(it1); it2 != v.end(); it2++) {
                        userSeqs.insert(it->second + "$" + it1->second + "#" + it2->second);
                    }
                }
            }
            for (auto userSeq : userSeqs) {
                count[userSeq]++;
            }
        }
        
        int maxCount = 0;
        string maxSeq;
        for (auto it : count) {
            if (it.second == maxCount) {
                maxSeq = min(it.first, maxSeq);
            }
            if (it.second > maxCount) {
                maxCount = it.second;
                maxSeq = it.first;
            }
        }
        
        auto p1 = maxSeq.find("$"), p2 = maxSeq.find("#");
        return { maxSeq.substr(0, p1), maxSeq.substr(p1 + 1, p2 - p1 - 1), maxSeq.substr(p2 + 1) };
    }
};