# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def depthHelper(self, root: Optional[TreeNode]) -> int:
        if root:
            return 1 + max(self.depthOfBinaryTree(root.left), self.depthOfBinaryTree(root.right))
        else:
            return 0

    def depthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.depthHelper(root)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxDiam = 0
        
        def dfs(root):
            nonlocal maxDiam

            if root:
                leftDepth = dfs(root.left)
                rightDepth = dfs(root.right)

                maxDiam = max(maxDiam, leftDepth + rightDepth)
                
                return 1 + max(leftDepth, rightDepth)
            else:
                return 0
        
        dfs(root)
        return maxDiam