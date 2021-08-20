class StringIterator {
public:
    int index, count;
    string str;
    char curr;
    StringIterator(string compressedString) {
        str = compressedString;
        index = count = 0;        
    }
    
    char next() {
        if (hasNext()) {
            count--;
            return curr;
        }
        return ' ';
    }
    
    bool hasNext() {
        if (count <= 0 && index >= str.length()) {
            return false;
        }
        if (count == 0) {
            curr = str[index];
            index++;
            while (index < str.length() && isdigit(str[index])) {\
                count = count * 10 + str[index] - '0';
                index++;
            }            
        }
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */