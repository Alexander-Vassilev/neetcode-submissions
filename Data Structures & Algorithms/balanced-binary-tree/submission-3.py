# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def isBalancedHelper(root: Optional[TreeNode]):
            if not root:
                return 0
            
            return 1 + max(isBalancedHelper(root.left), isBalancedHelper(root.right))

        leftBalanced = self.isBalanced(root.left)
        rightBalanced = self.isBalanced(root.right)

        if (not (leftBalanced and rightBalanced)):
            return False

        leftHeight = isBalancedHelper(root.left)
        rightHeight = isBalancedHelper(root.right)

        if (abs(leftHeight - rightHeight) > 1):
            return False
        else:
            return True