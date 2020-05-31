# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        count, node = 0, root
        ans = []
        while node:
            count += 1
            node = node.next

        num, remainder = count // k, count % k
        node = root
        for i in range(k):
            head = node
            for _ in range(num + (i < remainder) - 1):
                if node:
                    node = node.next
            if node:
                node.next, node = None, node.next
            ans.append(head)
        return ans

