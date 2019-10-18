# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:        
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        ans = 1
        def diameter(root):
            nonlocal ans
            if not root:
                return 0
            left = diameter(root.left)
            right = diameter(root.right)            
            ans = max(ans, left + right + 1)
            return max(left, right) + 1
        diameter(root)
        return ans - 1
        
