class Solution {
public:
    int minimumMoves(string s) {
        int move = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'X' && start == -1) {
                start = i;
            }
            if (start != -1 && i - start + 1 >= 3) {                
                move++;
                start = -1;
            }
        }
        return move + (start == -1 ? 0 : 1);
    }
};