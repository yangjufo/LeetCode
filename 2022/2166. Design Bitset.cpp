class Bitset {
public:
    string bits;
    unordered_map<char, int> countMap;
    unordered_map<char, char> bitMap;
    Bitset(int size) {
        bits = string(size, 'a');
        bitMap['0'] = 'a';
        bitMap['1'] = 'b';
        countMap['a'] = size;
        countMap['b'] = 0;
    }

    void fix(int idx) {
        if (bits[idx] != bitMap['1']) {
            countMap[bitMap['1']]++;
            countMap[bitMap['0']]--;
        }
        bits[idx] = bitMap['1'];
    }

    void unfix(int idx) {
        if (bits[idx] != bitMap['0']) {
            countMap[bitMap['0']]++;
            countMap[bitMap['1']]--;
        }
        bits[idx] = bitMap['0'];
    }

    void flip() {
        char tmp = bitMap['0'];
        bitMap['0'] = bitMap['1'];
        bitMap['1'] = tmp;
    }

    bool all() {
        return countMap[bitMap['1']] == bits.length();
    }

    bool one() {
        return countMap[bitMap['1']] > 0;
    }

    int count() {
        return countMap[bitMap['1']];
    }

    string toString() {
        string res;
        for (char c : bits) {
            if (bitMap['0'] == c) {
                res += '0';
            } else {
                res += '1';
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */