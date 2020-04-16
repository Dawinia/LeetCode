# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1, num2 = [], []
        ans = None
        node1 = l1
        node2 = l2
        while node1:
            num1.append(node1.val)
            node1 = node1.next

        while node2:
            num2.append(node2.val)
            node2 = node2.next

        rest = 0
        while num1 or num2 or rest != 0:
            a = 0 if not num1 else num1.pop()
            b = 0 if not num2 else num2.pop()
            e = a + b + rest
            rest = e // 10
            e %= 10
            cur = ListNode(e)
            cur.next = ans
            ans = cur

        return ans
            


