class Node {
public:
    bool end;
    Node* next[26];

    Node() {
        end = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};


class Encrypter {
public:
    unordered_map<char, int> keyMap;
    unordered_map<string, vector<int>> valueMap;
    vector<char> keys;
    vector<string> values;
    Node* dict;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = keys;
        for (int i = 0; i < keys.size(); i++) {
            keyMap[keys[i]] = i;
        }
        for (int i = 0; i < values.size(); i++) {
            valueMap[values[i]].push_back(i);
        }
        this->values = values;
        dict = new Node();
        for (string& s : dictionary) {
            Node* curr = dict;
            for (char c : s) {
                if (curr->next[c - 'a'] == nullptr) {
                    curr->next[c - 'a'] = new Node();
                }
                curr = curr->next[c - 'a'];
            }
            curr->end = true;
        }
    }

    string encrypt(string word1) {
        string res;
        for (char c : word1) {
            res += values[keyMap[c]];
        }
        return res;
    }

    int decrypt(string word2) {
        vector<Node*> prev = {dict};
        for (int index = 0; index < word2.size(); index += 2) {
            vector<Node*> curr;
            for (Node* p : prev) {
                for (int i : valueMap[word2.substr(index, 2)]) {
                    if (p->next[keys[i] - 'a'] != nullptr) {
                        curr.push_back(p->next[keys[i] - 'a']);
                    }
                }
            }
            prev = curr;
        }
        int count = 0;
        for (Node* p : prev) {
            if (p->end) {
                count++;
            }
        }
        return count;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */