class Solution {
public:
    int maxLen = 0;
    int maxLength(vector<string>& arr) {
        vector<int> counter(26, 0);        
        backtrack(arr, 0, counter, 0);
        return maxLen;
    }
    void backtrack(vector<string>& arr, int start, vector<int>& counter, int currLen) {
        maxLen = max(maxLen, currLen);
        for (int i = start; i < arr.size(); i++) {
            if (currLen + arr[i].length() > 26) continue;            
            int index = 0;
            while (index < arr[i].length()) {
                counter[arr[i][index] - 'a']++;
                if (counter[arr[i][index] - 'a'] > 1) {
                    break;
                }
                index++;
            }
            if (index >= arr[i].length()) {
                backtrack(arr, i + 1, counter, currLen + arr[i].length());
                index--;
            }            
            while (index >= 0) {
                counter[arr[i][index] - 'a']--;
                index--;
            }            
        }
    }
};

class Solution {
public:
    int maxLen = 0;
    int maxLength(vector<string>& arr) {
        vector<int> counter(26, 0);
        backtrack(arr, 0, counter, 0);
        return maxLen;
    }
    
    void backtrack(vector<string>& arr, int start, vector<int>& counter, int currLen) {
        maxLen = max(maxLen, currLen);
        for (int i = start; i < arr.size(); i++) {            
            int j = 0;
            while (j < arr[i].length() && counter[arr[i][j] - 'a'] == 0) {
                counter[arr[i][j] - 'a']++;
                j++;
            }
            if (j >= arr[i].length()) {
                backtrack(arr, i + 1, counter, currLen + arr[i].length());                
            }
            j--;
            while (j >= 0) {
                counter[arr[i][j] - 'a']--;
                j--;
            }                
        }
    }
};