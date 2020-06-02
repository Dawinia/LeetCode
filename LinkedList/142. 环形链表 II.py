# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        def get_intersect(head):

            slow = fast = head
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
                if slow == fast:
                    return slow
            return None
        
        fast = get_intersect(head)
        if not fast:
            return None
        
        slow = head
        while slow != fast:
            if not slow or not fast: return None
            slow = slow.next
            fast = fast.next
        return slow