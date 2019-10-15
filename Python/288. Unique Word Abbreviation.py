class ValidWordAbbr:

    def __init__(self, dictionary: List[str]):
        self.abbr = collections.defaultdict(int)
        self.dictionary = set(dictionary)
        for word in self.dictionary:
            if len(word) <= 2:
                self.abbr[word] += 1
            else:
                self.abbr[word[0] + str(len(word[1:-1])) + word[-1]] += 1

    def isUnique(self, word: str) -> bool:        
        if len(word) <= 2:
            abr = word
        else:
            abr = word[0] + str(len(word[1:-1])) + word[-1]        
        return abr not in self.abbr or (self.abbr[abr] == 1 and word in self.dictionary)
        


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
