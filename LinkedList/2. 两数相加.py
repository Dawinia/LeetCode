# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 or not l2: return None
        
        head = tmp = ListNode(-1)
        cb = 0
        while l1 or l2:
            cb += (l1.val if l1 else 0) + (l2.val if l2 else 0)
            tmp.next = ListNode(cb % 10)
            tmp = tmp.next
            cb //= 10
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        if cb:
            tmp.next = ListNode(cb)
        return head.next