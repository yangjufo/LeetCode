class Solution {
public:
    template <typename T>
    struct cmp
    {
        bool operator()(const T &x, const T &y)
        {
            return y.length() < x.length();
        }
    };

    int minimumLengthEncoding(vector<string>& words) {
        if (words.empty())
            return 0;
        string encodeString;
        int length = words.size();
        for (int i = 0; i < length; i++){
            words[i] += "#";
        }
        sort(words.begin(), words.end(), cmp<string>());
        encodeString = words[0];
        for (int i = 1; i < length; i++){
            if (encodeString.find(words[i]) != encodeString.npos)
                continue;
            encodeString += words[i];
        }
        return encodeString.length();
    }
};