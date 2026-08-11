# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque 

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        retList = []
        q = deque()
        q.append(root)

        while q:
            qlen = len(q)
            right = None

            for i in range(qlen):
                node = q.popleft()

                if node:
                    q.append(node.left)
                    q.append(node.right)
                
                    right = node.val
            
            if right:
                retList.append(right)

        return retList