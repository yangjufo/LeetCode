class Solution {
public:
    string reformatNumber(string number) {
        string groupNumber;
        int count = 0;
        for (char const &c : number) {
            if (c != ' ' && c != '-') {
                groupNumber += c;
                count++;
                if (count % 3 == 0) {
                    groupNumber += '-';
                }
            }                        
        }
        if (groupNumber.back() == '-') groupNumber.pop_back();
        else if (groupNumber[groupNumber.length() - 2] == '-') {
            groupNumber[groupNumber.length() - 2] = groupNumber[groupNumber.length() - 3];
            groupNumber[groupNumber.length() - 3] = '-';
        }
        return groupNumber;
    }
};