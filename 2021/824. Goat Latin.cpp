class Solution {
public:
    string toGoatLatin(string sentence) {
        int index = 1;
        sentence += " ";
        string word, res;
        for (char c : sentence) {
            if (c == ' ') {
                char key = tolower(word[0]);
                if (key != 'a' && key != 'e' && key != 'i' && key != 'o' && key != 'u') {                         word = word.substr(1) + word[0];                    
                }                
                word += "ma" + string(index, 'a');
                res += word + " ";
                index++;
                word.clear();
            } else {
                word += c;
            }
        }
        return res.substr(0, res.length() - 1);
    }
};