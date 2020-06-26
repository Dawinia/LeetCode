# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head: return None

        dummy = ListNode(0)
        dummy.next = head
        first = second = dummy
        for i in range(n + 1):
            if not first:
                return None
            first = first.next
        while first:
            first = first.next
            second = second.next
        
        if not second.next:
            return None
        second.next = second.next.next
        return dummy.next