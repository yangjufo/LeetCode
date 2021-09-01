class Solution {
public:
    string similarRGB(string color) {
        for (int i = 1; i < 7; i += 2) {
            int value = stoi(color.substr(i,2), nullptr, 16);
            int index = value/17 < 15 && value%17 > 8? value/17+1:value/17; 
            color[i] = color[i+1] = (index > 9? index-10+'a':index+'0');
        }        
        return color;
    }
};