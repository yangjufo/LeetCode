class Trie
{
public:
    bool isEnd;
    Trie *next[26];

    /** Initialize your data structure here. */
    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (node->next[c - 'a'] == NULL)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = searchPath(word);
        return node != NULL && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return searchPath(prefix) != NULL;
    }

private:
    Trie *searchPath(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (node->next[c - 'a'] == NULL)
                return NULL;
            node = node->next[c - 'a'];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */