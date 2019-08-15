"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        nodeMap = dict()
        def expand(node):
            newNode = Node(node.val, list())
            nodeMap[node] = newNode
            for neigh in node.neighbors:
                if neigh in nodeMap:
                    newNode.neighbors.append(nodeMap[neigh])
                else:
                    newNode.neighbors.append(expand(neigh))
            return newNode
        return expand(node)
            
        