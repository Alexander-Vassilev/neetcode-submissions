# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:        
        if not l1 and not l2:
            return None
        
        carry = 0
        node = ListNode()
        retVal = node

        while l1 or l2:
            val1 = 0
            val2 = 0

            if l1:
                val1 = l1.val
                l1 = l1.next
            
            if l2:
                val2 = l2.val
                l2 = l2.next
            
            res = val1 + val2 + carry
            resMod = res % 10

            if res == (resMod):
                carry = 0
            else:
                carry = 1
            
            node.next = ListNode(resMod)
            node = node.next
        
        if carry == 1:
            node.next = ListNode(1)

        return retVal.next