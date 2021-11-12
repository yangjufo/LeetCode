class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i1 = 0, i2 = 0;
        for (; i1 < name.length() && i2 < typed.length(); i1++) {
            if (i2 < typed.length() && name[i1] == typed[i2]) {
                i2++;
            } else {
                return false;
            }
            while (i2 < typed.length() && name[i1] == typed[i2] && ((i1 + 1 < name.length() && name[i1 + 1] != name[i1]) || i1 + 1 == name.length())) {
                i2++;
            }            
        }        
                
        return i2 >= typed.length() && i1 >= name.length();
    }
};