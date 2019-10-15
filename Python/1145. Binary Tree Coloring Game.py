# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        left = right = 0        
        def count(root):
            nonlocal left, right
            if root == None:
                return 0
            l = count(root.left)
            r = count(root.right)
            if root.val == x:
                left = l
                right = r            
            return l + r + 1
        count(root)        
        return max(left, right, n - left - right - 1) > n / 2