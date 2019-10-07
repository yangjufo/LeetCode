# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def isValid(root, left=float('-inf'), right=float('inf')):
            if not root:
                return True
            if root.val <= left or root.val >= right:
                return False
            return isValid(root.left, left, root.val) and isValid(root.right, root.val, right)
        if not root:
            return True
        return isValid(root)
