class TrieNode:    
    def __init__(self):
        self.next = [None] * 26
        self.word = False


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """        
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """                
        r = self.root
        for c in word:
            if r.next[ord(c) - ord('a')] is None:
                r.next[ord(c) - ord('a')] = TrieNode()
            r = r.next[ord(c) - ord('a')]
        r.word = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        r = self.root
        for c in word:
            if r.next[ord(c) - ord('a')] is None:
                return False
            r = r.next[ord(c) - ord('a')]
        return r.word

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        r = self.root
        for c in prefix:
            if r.next[ord(c) - ord('a')] is None:
                return False
            r = r.next[ord(c) - ord('a')]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
