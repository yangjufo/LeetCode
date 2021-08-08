class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int p : piles) {
            pq.push(p);
        }            
        for (int i = 0; i < k && !pq.empty(); i++) {
            int curr = pq.top();            
            pq.pop();
            if (curr - curr / 2 > 0) {
                pq.push(curr - curr / 2);
            }            
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};