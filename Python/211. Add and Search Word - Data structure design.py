from collections import defaultdict

class WordNode:
    
    def __init__(self):
        self.next = defaultdict(int)
        self.end = False

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = WordNode()
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        r = self.root
        for c in word:            
            if ord(c) not in r.next:
                r.next[ord(c)] = WordNode()
            r = r.next[ord(c)]
        r.end = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        def root_search(root, word):               
            for i in range(len(word)):                
                if word[i] == '.':
                    for n, node in root.next.items():
                        if root_search(node, word[i+1:]):
                            return True
                    return False
                elif ord(word[i]) not in root.next:
                    return False
                else:
                    root = root.next[ord(word[i])]
            return root.end
        return root_search(self.root, word)
        
                
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
