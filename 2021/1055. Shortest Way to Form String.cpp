class Solution {
public:
    int shortestWay(string source, string target) {
        int index = 0;
        for (int i = 0; i < target.length(); i++) {
            int start = index;
            while (index < start + source.length() && target[i] != source[index % source.length()]) {
                index++;
            }            
            if (index >= start + source.length()) {
                return -1;
            }
            index++;
        }
        return (index + source.length() - 1) / source.length();
    }
};