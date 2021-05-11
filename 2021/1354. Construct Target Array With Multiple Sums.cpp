class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total = 0;
        int n = target.size();
        priority_queue<int> pq(target.begin(), target.end());
        for (int a : target)
            total += a;
        int maxVal;
        while (true) {
            maxVal = pq.top(); pq.pop();
            total -= maxVal;
            if (maxVal == 1 || total == 1)
                return true;
            if (maxVal < total || total == 0 || maxVal % total == 0)
                return false;
            maxVal %= total;
            total += maxVal;
            pq.push(maxVal);
        }
    }
};