# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        retList = []
        layerList = []
        q = deque()
        q.append(root)

        while q:
            currLayer = []
            lenq = len(q)

            for i in range(lenq):
                node = q.popleft()

                if node:
                    currLayer.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
            
            if currLayer:
                retList.append(currLayer)

        return retList