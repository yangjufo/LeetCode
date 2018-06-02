class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        map<string, int> times;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), towlower);
        auto length = static_cast<int>(paragraph.length());
        int start = 0;
        string tmp_word;
        string res;
        int max_time = 0;
        for (int i = 0; i < length; i++) {
            if (((paragraph[i] == ' ' || paragraph[i] == ',' || paragraph[i] == '.' || paragraph[i] == ';'
                  || paragraph[i] == '?' || paragraph[i] == '\'' || paragraph[i] == '!')&&
                 (paragraph[i - 1] >= 'a' && paragraph[i - 1] <= 'z')) ||
                (i == length - 1 && paragraph[i] >= 'a' && paragraph[i] <= 'z')) {
                if (i == length - 1 && paragraph[i] >= 'a' && paragraph[i] <= 'z')
                    tmp_word = paragraph.substr(start, i - start + 1);
                else
                    tmp_word = paragraph.substr(start, i - start);

                while ((paragraph[i] == ' ' || paragraph[i] == ',' || paragraph[i] == '.' || paragraph[i] == ';'
                    || paragraph[i] == '?' || paragraph[i] == '\'' || paragraph[i] == '!'))
                    i++;
                start = i;
                if (i == length - 1)
                    ;
                else
                    i--;
                if (find(banned.begin(), banned.end(), tmp_word) != banned.end())
                    continue;
                if (times.count(tmp_word) != 0) {
                    times[tmp_word] += 1;
                } else
                    times[tmp_word] = 1;
                if (times[tmp_word] > max_time) {
                    max_time = times[tmp_word];
                    res = tmp_word;
                }
            }
        }
        return res;
    }
};