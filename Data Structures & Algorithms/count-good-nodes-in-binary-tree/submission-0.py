# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def goodNodesHelper(newRoot, maxVal):
            if not newRoot:
                return 0
            
            retVal = 0
            newMax = max(maxVal, newRoot.val)

            if newRoot.val >= maxVal:
                retVal += 1

            return retVal + goodNodesHelper(newRoot.left, newMax) + goodNodesHelper(newRoot.right, newMax)                
        
        return goodNodesHelper(root, -101)