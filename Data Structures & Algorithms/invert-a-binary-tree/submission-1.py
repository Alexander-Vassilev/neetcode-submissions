# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            if root.left or root.right:
                node = root.left
                root.left = self.invertTree(root.right)
                root.right = self.invertTree(node)

                return root
            else:
                return root
        else:
            return None