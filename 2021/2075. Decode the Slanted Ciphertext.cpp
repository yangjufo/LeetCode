class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string res(encodedText.length(), ' ');
        int cols = encodedText.length() / rows, index = 0;      
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((j - i) % cols * rows + i >= 0) {
                    res[(j - i) % cols * rows + i] = encodedText[index];                    
                }                
                index++;                
            }
        }        
        int len = res.length();
        while (len > 0 && res[len - 1] == ' ') {
            len--;
        }
        return res.substr(0, len);
    }
};