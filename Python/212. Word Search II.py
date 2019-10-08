class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        WORD_KEY = '$'
        
        trie = {}
        for word in words:
            node = trie
            for c in word:
                node = node.setdefault(c, {})
            node[WORD_KEY] = word
        rowNum = len(board)
        colNum = len(board[0])
        
        ans = list()
        
        def backtracking(row, col, parent):
            letter = board[row][col]
            currNode = parent[letter]
            word_match = currNode.pop(WORD_KEY, False)
            if word_match:
                ans.append(word_match)
            
            board[row][col] = '#'
            
            for (i, j) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                x, y = row + i, col + j
                if x < 0 or x >= rowNum or y < 0 or y >= colNum or board[x][y] not in currNode:
                    continue
                backtracking(x, y, currNode)
            
            board[row][col] = letter
            
            if not currNode:
                parent.pop(letter)
        
        for row in range(rowNum):
            for col in range(colNum):
                if board[row][col] in trie:
                    backtracking(row, col, trie)
        return ans
            
