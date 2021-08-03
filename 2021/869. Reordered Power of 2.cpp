class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> counter = count(N);
        for (int i = 0; i < 31; i++) {
            if (counter == count(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> count(int N) {
        vector<int> counter(10, 0);
        while (N > 0) {
            counter[N % 10]++;
            N /= 10;
        }
        return counter;
    }
};

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string strN = to_string(n);
        return backtrack(strN, 0);
    }
    
    bool backtrack(string& strN, int index) {          
        int num = stoi(strN); 
        for (int i = 0; i < 31; i++) {                    
            if (num == (1 << i)) {
                return true;
            } 
        }        
        for (int i = index; i < strN.length(); i++) {
            if ((index == 0 && strN[i] == '0') || (index > 0 && index != i && strN[i] == strN[i - 1])) {
                continue;
            }
            swap(strN[index], strN[i]);
            if (backtrack(strN, index + 1)) {
                return true;
            }
            swap(strN[i], strN[index]);
        }
        return false;
    }
};

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nDigitCount = countDigits(n);
        for (int i = 0; i < 32; i++) {
            if (nDigitCount == countDigits(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> countDigits(int n) {
        vector<int> counts(10, 0);
        while (n > 0) {
            counts[n % 10]++;
            n /= 10;
        }
        return counts;
    }
};