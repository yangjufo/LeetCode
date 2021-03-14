class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> counter(26, 0);
            counter[s[i] - 'a']++;
            for (int j = i + 1; j < s.length(); j++) {
                counter[s[j] - 'a']++;
                sum += diff(counter);
            }
        }        
        return sum;
    }
    
    int diff(vector<int>& counter) {
        int minVal = INT_MAX, maxVal = 0;
        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0) {
                minVal = min(minVal, counter[i]);
                maxVal = max(maxVal, counter[i]);
            }
        }        
        return maxVal - minVal;
    }
};