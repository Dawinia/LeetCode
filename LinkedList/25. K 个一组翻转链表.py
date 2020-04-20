# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k < 1:
            return head
        dummy = temp = ListNode(0)
        temp.next = left = right = head
        while True:
            count = 0
            while right and count < k:
                right, count = right.next, count + 1
            if count == k:
                for _ in range(k - 1):
                    cur = left.next
                    left.next = cur.next
                    cur.next = temp.next
                    temp.next = cur
                temp, left = left, right
            else:
                return dummy.next
