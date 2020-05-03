# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        size = len(lists)
        if size < 1:
            return None
        if size < 2:
            return lists[0]
        ans = ListNode(-1)
        ie = {}
        for i, e in enumerate(lists):
            ie[i + 1] = e
        temp = ans
        while True:
            mk = 0
            mv = ListNode(100000000)
            for k, v in ie.items():
                if v is None:
                    continue
                if v.val < mv.val:
                    mv, mk = v, k
            if mk == 0:
                break
            temp.next = ListNode(ie[mk].val)
            ie[mk] = ie[mk].next
            temp = temp.next
        return ans.next