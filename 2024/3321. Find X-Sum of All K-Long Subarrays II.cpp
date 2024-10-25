class Solution {
public:
    long long updateFirst(map<int, set<int>>& freqs,
                          map<int, set<int>>& cands) {
        int count = freqs.begin()->first,
            num = *(freqs.begin()->second.begin());
        removeNum(freqs, count, num);
        addNum(cands, count, num);
        return (long long)count * num;
    }

    long long updateLast(map<int, set<int>>& freqs, map<int, set<int>>& cands) {
        int count = prev(cands.end())->first,
            num = *(prev(prev(cands.end())->second.end()));
        removeNum(cands, count, num);
        addNum(freqs, count, num);
        return (long long)count * num;
    }

    void removeNum(map<int, set<int>>& map, int count, int num) {
        map[count].erase(num);
        if (map[count].empty()) {
            map.erase(count);
        }
    }

    void addNum(map<int, set<int>>& map, int count, int num) {
        map[count].insert(num);
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<int, set<int>> freqs;
        map<int, set<int>> cands;
        unordered_map<int, int> counts;
        long long xSum = 0;
        vector<long long> res;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= k - 1) {
                counts[nums[i]] += 1;
            }
            if (i == k - 1) {
                for (auto& [k, v] : counts) {
                    freqs[v].insert(k);
                }
                total = counts.size();
                while (total > x) {
                    while (total > x && !freqs.begin()->second.empty()) {
                        updateFirst(freqs, cands);
                        total -= 1;
                    }
                }
                for (auto& [k, s] : freqs) {
                    for (auto v : s) {
                        xSum += (long long)v * k;
                    }
                }
                res.push_back(xSum);
            } else if (i >= k) {
                int dNum = nums[i - k], dCount = counts[nums[i - k]];
                counts[dNum] -= 1;
                if (freqs.find(dCount) != freqs.end() &&
                    freqs[dCount].find(dNum) != freqs[dCount].end()) {
                    removeNum(freqs, dCount, dNum);
                    xSum = xSum - (long long)dCount * dNum;
                    total -= 1;
                    if (dCount - 1 > 0) {
                        addNum(cands, dCount - 1, dNum);
                    }
                    if (!cands.empty()) {
                        xSum = xSum + updateLast(freqs, cands);
                        total += 1;
                    }
                } else if (cands.find(dCount) != cands.end() &&
                           cands[dCount].find(dNum) != cands[dCount].end()) {
                    removeNum(cands, dCount, dNum);
                    if (dCount - 1 > 0) {
                        addNum(cands, dCount - 1, dNum);
                    }
                }
                int nNum = nums[i], nCount = counts[nums[i]];
                counts[nums[i]] += 1;
                if (freqs.find(nCount) != freqs.end() &&
                    freqs[nCount].find(nNum) != freqs[nCount].end()) {
                    removeNum(freqs, nCount, nNum);
                    xSum = xSum - (long long)nCount * nNum;
                    total -= 1;
                    addNum(freqs, counts[nums[i]], nums[i]);
                    xSum += (long long)nums[i] * counts[nums[i]];
                    total += 1;
                } else if (total < x ||
                           counts[nums[i]] > freqs.begin()->first ||
                           (counts[nums[i]] == freqs.begin()->first &&
                            nNum > *(freqs.begin()->second.begin()))) {
                    if (cands.find(nCount) != cands.end() && cands[nCount].find(nNum) != cands[nCount].end()) {
                        removeNum(cands, nCount, nNum);
                    }
                    if (total >= x) {
                        xSum = xSum - updateFirst(freqs, cands);
                        total -= 1;
                    }
                    addNum(freqs, counts[nums[i]], nums[i]);
                    xSum += (long long)nums[i] * counts[nums[i]];
                    total += 1;
                } else {
                    if (cands.find(nCount) != cands.end() && cands[nCount].find(nNum) != cands[nCount].end()) {
                        removeNum(cands, nCount, nNum);
                    }
                    addNum(cands, nCount + 1, nNum);
                }
                res.push_back(xSum);
            }
        }
        return res;
    }
};