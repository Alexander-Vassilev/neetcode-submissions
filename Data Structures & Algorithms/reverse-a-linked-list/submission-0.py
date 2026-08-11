# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l = head
        retList = None

        while l is not None:
            retList = ListNode(l.val, retList)
            l = l.next

        return retList