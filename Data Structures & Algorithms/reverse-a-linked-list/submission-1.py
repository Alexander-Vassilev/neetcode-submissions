# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        l = head
        prev = None

        while l is not None:
            temp = l.next
            l.next = prev
            prev = l
            l = temp

        return prev