# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def __init__(self):
        self.str = ""

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return "#"
        res = str(root.val) + "#"
        res += self.serialize(root.left)
        res += self.serialize(root.right)
        return res

    def des(self):
        num = 0
        first = self.str.find("#")
        if first == 0:
            self.str = self.str[1:]
            return None
        root = TreeNode(int(self.str[0:first]))
        self.str = self.str[first + 1:]
        root.left = self.deserialize(self.str)
        root.right = self.deserialize(self.str)
        return root

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        self.str = data
        return self.des()


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
