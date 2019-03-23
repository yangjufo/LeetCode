class TrieNode {
private:
	TrieNode* links[26];	
	bool isEnd;

public:
	TrieNode() {
		for (int i = 0; i < 26; i++){
			links[i] = NULL;
		}
		isEnd = false;
	}

	bool containsKey(char ch) {
		return links[ch -'a'] != NULL;
	}

	TrieNode* get(char ch) {
		return links[ch - 'a'];
	}

	void put(char ch, TrieNode* node) {
		links[ch - 'a'] = node;
	}

	void setEnd() {
		isEnd = true;
	}

	bool end() {
		return isEnd;
	}
};

class WordDictionary {
private:
	TrieNode* root;

	bool searchPrefix(string word, TrieNode* startNode) {
		TrieNode* node = startNode;
		for (int i = 0; i < word.length(); i++) {
			char currentLetter = word[i];
            if (currentLetter == '.'){                
                for (char c = 'a'; c != 'z'; c++)
                {
                    if (node->containsKey(c)) {			        
                        if (searchPrefix(word.substr(i + 1, word.length() - i - 1), node->get(c))){
                            return true;
                        }
                    }
                }
                return false;
            }
			if (node->containsKey(currentLetter)) {
				node = node->get(currentLetter);
			}
			else {
				return false;
			}
		}
		return node->end();
	}

public:

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* node = root;
		for (int i = 0; i < word.length(); i++) {
			char currentChar = word[i];            
			if (!node->containsKey(currentChar)) {
				node->put(currentChar, new TrieNode());
			}
			node = node->get(currentChar);
		}
		node->setEnd();
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return searchPrefix(word, root);		
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */