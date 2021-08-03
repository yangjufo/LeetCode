class Solution {
public:
    int getMinSwaps(string num, int k) {
        int minSwap = num.length();
        string original(num);
        while (k > 0) {
            next_permutation(num.begin(), num.end());
            k--;            
        }
        return countSteps(original, num);
    }
    
    int countSteps(string& original, string& num) {
        int steps = 0, i = 0;
        while (i < num.size()) {
            int j = i;
            while (original[i] != num[j]) j++;
            while (i < j) {
                swap(num[j], num[j - 1]);
                j--;
                steps++;
            }
            i++;
        }
        return steps;
    }    
    
};