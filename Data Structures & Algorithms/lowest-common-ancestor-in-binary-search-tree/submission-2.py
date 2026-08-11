# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not p or not q:
            return None
        
        if (root is p) or (root is q):
            return root
        elif (p.val > root.val) and (q.val > root.val):
            return self.lowestCommonAncestor(root.right, p, q)
        elif (p.val < root.val) and (q.val < root.val):
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root
    
test1 = TreeNode(6)
test2 = TreeNode(3)
test3 = TreeNode(4)
test4 = TreeNode(5)
test5 = TreeNode(5.5)
test1.left = test2
test2.right = test3
test3.right = test4
test4.right = test5


#sol = Solution()
#print(sol.lowestCommonAncestor(None, test4, test5).val)