import math

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head:
            return None
        
        index = 0
        node = head

        while node:
            index += 1
            node = node.next
        
        halfway = math.ceil(index / 2)
        index = 0
        node = head

        while index < halfway - 1:
            index += 1
            node = node.next
        
        temp = node.next
        node.next = None
        node = temp

        prev = None
        index = 0

        # Reverse second half of list
        while node:
            temp = node.next
            node.next = prev
            prev = node
            node = temp
        
        nodeBack = prev
        nodeFront = head
        advanceFront = True

        while nodeFront or nodeBack:
            if advanceFront:
                temp = nodeFront.next
                nodeFront.next = nodeBack
                nodeFront = temp
                advanceFront = False
            else:
                temp = nodeBack.next
                nodeBack.next = nodeFront
                nodeBack = temp
                advanceFront = True
