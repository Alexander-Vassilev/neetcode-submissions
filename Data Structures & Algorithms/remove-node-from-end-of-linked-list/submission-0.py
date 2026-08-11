# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        node = head

        while node:
            count += 1
            node = node.next
        
        node = head
        prev = None
        index = 0
        print(count)
        while node:
            print(index)
            if count - index == n:
                #print(prev.val)
                #print(node.next.val)

                if index == 0:
                    print("engere")
                    head = node.next
                else:
                    prev.next = node.next
                break
            else:
                index += 1
                prev = node
                node = node.next
        
        return head