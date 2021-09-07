class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> duration(26, 0);
        int prev = 0, maxDuration = 0;
        char res = 'z';        
        for (int i = 0; i < keysPressed.length(); i++) {
            duration[keysPressed[i] - 'a'] = max(releaseTimes[i] - prev, duration[keysPressed[i] - 'a']);
            prev = releaseTimes[i];   
            if (duration[keysPressed[i] - 'a'] > maxDuration || (duration[keysPressed[i] - 'a'] == maxDuration && keysPressed[i] > res)) {
                maxDuration = duration[keysPressed[i] - 'a'];
                res = keysPressed[i];
            }
        }                
        return res;
    }
};