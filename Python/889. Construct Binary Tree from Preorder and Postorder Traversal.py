# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    preIndex, posIndex = 0, 0
    def constructFromPrePost(self, pre, post):
        root = TreeNode(pre[self.preIndex])
        self.preIndex += 1
        if (root.val != post[self.posIndex]):
            root.left = self.constructFromPrePost(pre, post)
        if (root.val != post[self.posIndex]):
            root.right = self.constructFromPrePost(pre, post)
        self.posIndex += 1
        return root