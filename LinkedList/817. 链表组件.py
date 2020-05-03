
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: list) -> int:
        ans = 0
        flag = 0
        G = set(G)
        while head:
            if head.val in G:
                flag = 1
            else:
                if flag:
                    ans += 1
                    flag = 0
            head = head.next
        return ans + flag