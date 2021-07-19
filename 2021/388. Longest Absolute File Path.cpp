class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> levels(300, 0);
        int level = 0, res = 0, length = 0;
        bool file = false;
        for (char c : input) {
            switch(c) {
                case '\n':
                    level = 0;
                    length = 0;
                    file = false;
                    break;
                case '\t':
                    level++;
                    break;
                case '.':
                    file = true;
                    length++;
                    break;
                default:
                    length++;
                    levels[level] = length;                    
                    if(file){
                        res = max(res, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level);
                    }
                    break;
            }
        }
        return res;
    }
};