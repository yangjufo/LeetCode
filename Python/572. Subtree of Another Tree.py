# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def isSame(s, t):
            if s == None and t == None:
                return True
            if s == None or t == None:
                return False
            if s.val == t.val and isSame(s.left, t.left) and isSame(s.right, t.right):
                return True
        if s == None and t == None:
            return True
        if s == None or t == None:
            return False
        return isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
