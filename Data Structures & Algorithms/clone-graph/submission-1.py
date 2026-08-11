"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        seenDict = {}

        def cloneGraphHelper(node):
            if not node:
                return None
            elif node in seenDict:
                return seenDict[node]
            
            retNode = Node(node.val, [])
            seenDict[node] = retNode

            for neighbour in node.neighbors:
                retNode.neighbors.append(cloneGraphHelper(neighbour))
            
            return retNode
        
        return cloneGraphHelper(node)