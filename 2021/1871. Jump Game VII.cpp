class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> pos;
        pos.push(0);                
        int index = 0;
        while (!pos.empty()) {
            int curr = pos.front();            
            pos.pop();
            if (curr + 1 >= s.length()) return true;
            for (int i = max(index, curr + minJump); i <= curr + maxJump && i < s.length(); i++) {
                if (s[i] == '0') {
                    pos.push(i);
                }
            }
            index = max(index, curr + maxJump);
        }
        return false;
    }
};