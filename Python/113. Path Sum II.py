# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        ans = []
        def expand(root, curr, tmp_sum):
            if root == None:
                if tmp_sum == target:
                    ans.append(curr)
            else:
                if root.left != None:
                    expand(root.left, curr + [root.val], tmp_sum + root.val)
                if root.right != None:
                    expand(root.right, curr + [root.val], tmp_sum + root.val)
                if root.left == None and root.right == None:
                    expand(root.left, curr + [root.val], tmp_sum + root.val)
        expand(root, [], 0)
        return ans if root else []
                    