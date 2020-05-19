# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        ans, q, row = [], [root, '#'], []

        while len(q):
            node = q.pop(0)
            if node == '#':
                ans.append(row)
                if not len(q):
                    break
                q.append(node)
                row = []
                continue
            else:
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            row.append(node.val)
        return ans