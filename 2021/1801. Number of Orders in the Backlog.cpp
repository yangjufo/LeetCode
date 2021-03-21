class Solution {
public:
    int mod = 1'000'000'007;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {        
        priority_queue<pair<int,int>> buys;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> sells;
        long long total = 0;
        
        for (vector<int>& order : orders) {
            if (order[2] == 0) {
                int amount = order[1], price = order[0];
                while (amount > 0 && !sells.empty() && price >= sells.top().first) {
                    pair<int, int> s = sells.top();
                    sells.pop();
                    total = total - s.second;
                    if (amount > s.second) {
                        amount -= s.second;
                    } else {
                        s.second -= amount;                        
                        amount = 0;
                        if (s.second > 0) {
                            total = total + s.second;
                            sells.push(s);
                        }                        
                    }
                }
                if (amount > 0) {
                    total = total + amount;
                    buys.push({price, amount});
                }
            } else {
                int amount = order[1], price = order[0];
                while (amount > 0 && !buys.empty() && price <= buys.top().first) {
                    pair<int, int> b = buys.top();
                    buys.pop();
                    total = total - b.second;
                    if (amount > b.second) {
                        amount -= b.second;
                    } else {
                        b.second -= amount;
                        amount = 0;
                        if (b.second > 0) {
                            total = total + b.second;
                            buys.push(b);
                        }
                    }
                }
                if (amount > 0) {
                    total = total + amount;
                    sells.push({price, amount});
                }
            }            
        }
        return total % mod;
    }
};