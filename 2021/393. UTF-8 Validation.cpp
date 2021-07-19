class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 0;
        for (int d : data) {
            string binary = bitset<8>(d).to_string();  
            if (bytes == 0) {
                int index = 0;
                while (index < binary.length() && binary[index] == '1') {
                    index++;
                }
                if (index == 1 || index > 4 || (index > 0 && binary[index] != '0')) {
                    return false;
                }
                bytes = max(index - 1, 0);
            } else {
                if (binary[0] != '1' || binary[1] != '0') {
                    return false;
                }
                bytes--;
            }
        }                
        return bytes == 0;
    }
};