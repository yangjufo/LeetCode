class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        string fraction;
        if ((numerator < 0) ^ (denominator < 0)) {
            fraction += "-";
        }
        
        long dvd = labs(numerator), dvs = labs(denominator);
        fraction += to_string(dvd / dvs);
        long rem = dvd % dvs;
        if (rem == 0) {
            return fraction;
        }
        
        fraction += '.';
        unordered_map<long, int> digitMap;
        
        while (rem != 0) {
            if (digitMap.find(rem) != digitMap.end()) {
                fraction.insert(digitMap[rem], "(");
                fraction.append(")");
                break;
            }
            digitMap[rem] = fraction.length();
            rem *= 10;
            fraction += to_string(rem / dvs);
            rem %= dvs;
        }
        return fraction;
    }
};