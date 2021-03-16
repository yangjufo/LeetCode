class Solution {
public:    
    unordered_map<int, string> decodeMap;
    int index = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {        
        decodeMap[index] = longUrl;
        index++;
        return to_string(index - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));