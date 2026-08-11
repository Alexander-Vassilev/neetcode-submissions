"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        oldToNew = {}
        oldToNew[None] = None
        node = head
        copy = Node(0)

        while node:
            copy.val = node.val

            if node.next:
                copy.next = Node(0)

            oldToNew[node] = copy
            copy = copy.next
            node = node.next
        
        node = head

        while node:
            rand = oldToNew[node.random]
            oldToNew[node].random = rand
            node = node.next
        
        return oldToNew[head]