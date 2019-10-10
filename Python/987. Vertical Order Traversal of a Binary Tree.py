# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import queue

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        levels = queue.Queue()
        nodes = queue.Queue()
        nodes.put(root)
        levels.put((0,0))
        out = dict()
        while not nodes.empty():
            node = nodes.get()
            level = levels.get()
            if level[0] not in out:
                out[level[0]] = dict()
            if level[1] not in out[level[0]]:
                out[level[0]][level[1]] = list()            
            out[level[0]][level[1]].append(node.val)
            if node.left:
                nodes.put(node.left)
                levels.put((level[0] - 1, level[1] + 1))
            if node.right:
                nodes.put(node.right)
                levels.put((level[0] + 1, level[1] + 1))
        ans = list()        
        for x in sorted(out):
            line = list()
            for y in sorted(out[x]):
                line.extend(sorted(out[x][y]))
            ans.append(line)
        return ans
