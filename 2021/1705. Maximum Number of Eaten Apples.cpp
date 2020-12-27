class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        auto Compare = [](auto &a, auto &b) { return (a.second == b.second) ? a.first < b.first : a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(Compare)> pq(Compare);        
        int startingDay = -1;
        for (int i = 0; i < apples.size(); i++) {
            if (apples[i] != 0) {
                pq.push({apples[i], i + days[i]});
                if (startingDay == -1) startingDay = i;
            }                    
        }
        
        int day = startingDay, count = 0;        
         while (!pq.empty()) {
             while (!pq.empty() && pq.top().second <= day) {                
                 pq.pop();
             }
             if (!pq.empty()) {                 
                 auto top = pq.top();                     
                 pq.pop();
                 count++;
                 if (top.first > 1) {                     
                     pq.push({top.first - 1, top.second});
                 }                 
             }
             day++;
         }                
        
        return count;
    }
};