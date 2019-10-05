# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        num = set()
        right = list()
        right.append(root1)
        while len(right) != 0:            
            node = right.pop()
            num.add(node.val)            
            if node.right != None:
                right.append(node.right)            
            if node.left != None:
                right.append(node.left)
        right.append(root2)
        while len(right) != 0:
            node = right.pop()
            if target - node.val in num:
                return True
            if node.right != None:
                right.append(node.right)            
            if node.left != None:
                right.append(node.left)
        return False
            
            