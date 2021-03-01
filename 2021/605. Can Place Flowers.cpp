class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, zeros = 0;
        bool first = true;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                zeros++;                
            } else {
                count += first ? zeros / 2 : (zeros - 1) / 2;
                zeros = 0;
                first = false;
            }
        }        
        count += zeros > 0 ? (first ? (zeros + 1) / 2 : zeros / 2) : 0;
        return count >= n;
    }
};