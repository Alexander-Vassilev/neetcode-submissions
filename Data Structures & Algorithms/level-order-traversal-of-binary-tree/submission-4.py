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
        q.append([root, True])

        while q:
            curr = q.popleft()
            isEnd = False
            layerList.append(curr[0].val)

            if curr[1]:
                retList.append(layerList)
                layerList = []
                isEnd = True

                if (not curr[0].left) and (not curr[0].right) and q:
                    q[-1][1] = True

            if curr[0].left:
                isEnd2 = False

                if not curr[0].right:
                    isEnd2 = isEnd

                q.append([curr[0].left, isEnd2])
            
            if curr[0].right:
                q.append([curr[0].right, isEnd])

            #for l in q:
            #    print(str(l[0].val) + ": " + str(l[1]))
            #print("next")
        
        if layerList:
            retList.append(layerList)

        return retList