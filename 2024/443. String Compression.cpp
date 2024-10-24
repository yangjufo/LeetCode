class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, index = 0;
        while (index < chars.size()) {
            int begin = index;
            while (index < chars.size() && chars[index] == chars[begin]) {
                index += 1;
            }
            for (char c :
                 chars[begin] +
                     (index - begin == 1 ? "" : to_string(index - begin))) {
                chars[start] = c;
                start += 1;
            }
        }
        return start;
    }
};