class StockPrice {
public:
    map<int, int> prices;
    map<int, int> count;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (prices.find(timestamp) != prices.end()) {
            count[prices[timestamp]]--;
            if (count[prices[timestamp]] == 0) {
                count.erase(prices[timestamp]);
            }
        }        
        prices[timestamp] = price;
        count[price]++;
    }
    
    int current() {
        return prices.rbegin()->second;
    }
    
    int maximum() {
        return count.rbegin()->first;
    }
    
    int minimum() {
        return count.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */