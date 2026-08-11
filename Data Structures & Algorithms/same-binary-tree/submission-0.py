# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (not p) and (not q):
            return True
        elif (not p) or (not q):
            return False
        elif p.val == q.val:
            leftMatch = self.isSameTree(p.left, q.left)
            rightMatch = self.isSameTree(p.right, q.right)

            return (leftMatch and rightMatch)
        else:
            return False