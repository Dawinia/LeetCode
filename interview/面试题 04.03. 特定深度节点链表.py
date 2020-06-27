# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        if not tree: return []

        queue = [tree, '#']
        ans, row, head = [], None, None
        while len(queue):
            node = queue.pop(0)
            if node == '#':
                if not head:
                    return ans
                ans.append(head)
                head = row = None
                queue.append('#')
            else:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                if not head:
                    head = row = ListNode(node.val)
                else:
                    row.next = ListNode(node.val)
                    row = row.next
        return ans


