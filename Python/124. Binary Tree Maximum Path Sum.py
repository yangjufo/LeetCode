# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def __init__(self):
        self.ans = 0

    def maxOne(self, root):
        if root == None:
            return 0
        left = max(self.maxOne(root.left), 0)
        right = max(self.maxOne(root.right), 0)
        self.ans = max(self.ans, left + right + root.val)
        return root.val + max(left, right)

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        self.ans = root.val
        self.maxOne(root)
        return self.ans
