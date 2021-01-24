class Solution {
public:
    int minCharacters(string a, string b) {        
        int countA[26], countB[26];
        for (int i = 0; i < 26; i++) {
            countA[i] = countB[i] = 0;
        }
        for (char c : a) {
            countA[c - 'a']++;
        }
        for (char c : b) {
            countB[c - 'a']++;
        }
        
        int mostA = 0, mostB = 0;
        for (int i = 0; i < 26; i++) {
            if (countA[i] > mostA) mostA = countA[i];
            if (countB[i] > mostB) mostB = countB[i];
        }
        
        int res = a.length() + b.length();        
        for (int i = 0; i < 25; i++) {
            countA[i + 1] += countA[i];
            countB[i + 1] += countB[i];
            int aFilp = a.length() - countA[i] + countB[i];
            int bFilp = b.length() - countB[i] + countA[i];
            res = min(res, min(aFilp, bFilp));
        }
        int unique = a.length() - mostA + b.length() - mostB;
        return min(res, unique);
    }
};