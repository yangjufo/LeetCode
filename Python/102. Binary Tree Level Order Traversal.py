# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import Queue as queue


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        nq = queue.Queue()
        level = queue.Queue()
        nq.put(root)
        level.put(1)
        ans = []
        while not nq.empty():
            node = nq.get()
            curr = level.get()
            if len(ans) < curr:
                ans.append(list())
            ans[-1].append(node.val)
            if node.left != None:
                nq.put(node.left)
                level.put(curr + 1)
            if node.right != None:
                nq.put(node.right)
                level.put(curr + 1)
        return ans
