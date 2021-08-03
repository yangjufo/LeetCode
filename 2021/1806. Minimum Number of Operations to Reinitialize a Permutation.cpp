class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n, 0), arr(n, 0);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        int count = 0;        
        do {            
            for (int i = 0; i < n; i++) {
                if ((i & 0x1) == 1) {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                } else {
                    arr[i] = perm[i / 2];
                }
            }
            count++;
            perm = arr;
        } while (!isOriginal(perm, n));    
        return count;
    }
    
    bool isOriginal(vector<int>& perm, int n) {
        for (int i = 0; i < n; i++) {
            if (perm[i] != i) return false;
        }
        return true;
    }
};

class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0, i = 1;
        while (res == 0 || i > 1) {
            if (i < n / 2)
                i *= 2;
            else
                i = (i - n / 2) * 2 + 1;
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int reinitializePermutation(int n) {
        int count = 0, index = 1;
        while (count == 0 || index > 1) {
            if (index < n / 2) {
                index *= 2;
            } else {
                index = (index - n / 2) * 2 + 1;
            }
            count++;
        }
        return count;
    }
};