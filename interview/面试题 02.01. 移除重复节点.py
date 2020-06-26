# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        if not head: return None
        dummy = ListNode(-1)
        dummy.next = head
        prev = ListNode(-1)
        prev.next = head
        seen = set()
        while head:
            if head.val not in seen:
                seen.add(head.val)
                prev, head = head, head.next
            else:
                head = head.next
                prev.next = head
        return dummy.next