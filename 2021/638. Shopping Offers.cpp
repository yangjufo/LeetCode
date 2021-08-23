class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return backtrack(price, special, needs, 0);
    }
    
    int backtrack(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int index) {
        int res = directPurshase(price, needs);
        for (int i = index; i < special.size(); i++) {
            if (isValid(needs, special[i])) {
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] -= special[i][j];
                }
                res = min(res, special[i].back() + backtrack(price, special, needs, i));
                for (int j = 0; j < needs.size(); j++) {
                    needs[j] += special[i][j];
                }
            }
        }
        return res;
    }
    
    
    bool isValid(vector<int>& needs, vector<int>& special) {
        for (int i = 0; i < needs.size(); i++) {
            if (needs[i] < special[i]) {
                return false;
            }
        }
        return true;
    }
    
    int directPurshase(vector<int>& price, vector<int>& needs) {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += price[i] * needs[i];
        }
        return sum;
    }
};