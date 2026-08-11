# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def BSTHelper(node, low, high):
            if not node:
                return True

            if not (low < node.val < high):
                return False

            return BSTHelper(node.left, low, node.val) and BSTHelper(node.right, node.val, high)
        
        return BSTHelper(root, float('-inf'), float('inf'))