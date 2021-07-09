class Solution {
public:
    vector<int> maxNumber(vector<int>& num1, vector<int>& num2, int k) {
        vector<int> ans(k, 0);        
        for (int i = max(0, k - (int)num2.size()); i <= num1.size(); i++) {
            vector<int> candidate =  merge(maxArray(num1, i), maxArray(num2, k - i), k);
            if (greater(candidate, 0, ans, 0)) ans = candidate;            
        }
        return ans;
    }
    
    vector<int> maxArray(vector<int>& num, int k) {
        vector<int> ans;
        for (int i = 0; i < num.size(); i++) {
            while (!ans.empty() && num[i] > ans.back() && ans.size() + num.size() - i > k) {
                ans.pop_back();
            }
            if (ans.size() < k) {
                ans.push_back(num[i]);                
            }                         
        }
        return ans;        
    }
    
    vector<int> merge(vector<int> num1, vector<int> num2, int k) {
        int i = 0, j = 0;
        vector<int> ans;
        while (ans.size() < k) {
            if (greater(num1, i, num2, j)) {
                ans.push_back(num1[i]);
                i++;
            } else {
                ans.push_back(num2[j]);
                j++;
            }
        }
        return ans;
    }
    
    bool greater(vector<int>& num1, int index1, vector<int>& num2, int index2) {
        while (index1 < num1.size() && index2 < num2.size() && num1[index1] == num2[index2]) {
            index1++;
            index2++;
        }
        return index2 >= num2.size() || (index1 < num1.size() && num1[index1] > num2[index2]);
    }
};