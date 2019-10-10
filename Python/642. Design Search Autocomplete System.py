class TrieNode:
    
    def __init__(self):
        self.next = dict()        
        self.sentences = dict()

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        for i in range(len(sentences)):
            self.add(sentences[i], times[i])
        self.curr = self.root
        self.query = ""
        self.include = True
            
    def add(self, sentence, time):
        r = self.root
        for c in sentence:
            if c not in r.next:
                r.next[c] = TrieNode()            
            r = r.next[c]
            if sentence not in r.sentences:
                r.sentences[sentence] = 0
            r.sentences[sentence] += time

    def input(self, c: str) -> List[str]:
        r = self.curr
        ans = []
        if c == '#':            
            self.add(self.query, 1)                 
            self.curr = self.root
            self.include = True
            self.query = ""                        
        else:
            self.query += c
            if not self.include or c not in self.curr.next:
                self.include = False                
            else:                
                self.curr = self.curr.next[c]                  
                ans = [sen for sen, _ in sorted(self.curr.sentences.items(), key=lambda x: (-x[1], x[0]))[:3]]                     
        return ans


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
