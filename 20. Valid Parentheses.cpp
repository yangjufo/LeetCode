class Solution {
public:
    bool isValid(string s) {
        vector<char> tmp_stack;
        char tmp;
        map<char, char> brackets = {pair<char, char>('(', ')'), pair<char, char>('{', '}'), pair<char, char>('[', ']')};
        for (char i : s) {
            if (brackets.count(i) != 0)
                tmp_stack.push_back(i);
            else {
                if (tmp_stack.empty())
                    return false;
                tmp = tmp_stack.back();
                if (brackets[tmp] == i)
                    tmp_stack.pop_back();
                else
                    return false;
            }
        }
        return tmp_stack.empty();
    }
};