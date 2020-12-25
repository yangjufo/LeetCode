class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string s : strs) {
            res += to_string(s.length()) + "#";
            res += s;
        }
        return res;        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        string len;
        int index = 0;
        vector<string> res;
        while (index < s.length()) {            
            while (s[index] != '#') {
                len += s[index];
                index++;
            }
            index++;
            int count = stoi(len);
            res.push_back(s.substr(index, count));
            index += count;         
            len = "";
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));