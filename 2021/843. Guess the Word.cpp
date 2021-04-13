/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int t = 0, x = 0; t < 10 && x < 6; t++) {            
            vector<vector<int>> scoreCount(6, vector<int>(26, 0));            
            for (string& w : wordlist) {
                for (int i = 0; i < 6; i++) {
                    scoreCount[i][w[i] - 'a']++;
                }
            }
            
            int maxScore = 0;
            string best = wordlist[0];
            for (string& w : wordlist) {
                int score = 0;
                for (int i = 0; i < 6; i++) {
                    score += scoreCount[i][w[i] - 'a'];
                }
                if (score > maxScore) {
                    maxScore = score;
                    best = w;
                }
            }
            
            x = master.guess(best);
            vector<string> wordlist2;            
            for (string& w : wordlist) {
                if (matchCount(w, best) == x) {
                    wordlist2.push_back(w);
                }
            }
            wordlist = wordlist2;
        }
    }
    
    int matchCount(string& word1, string& word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] == word2[i]) count++;
        }
        return count;
    }
};