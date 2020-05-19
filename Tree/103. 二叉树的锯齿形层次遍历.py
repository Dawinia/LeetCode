# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        ans, q, level = [], [root], 0

        while len(q):
            levelSize, level = len(q), level + 1
            row = []

            for i in range(levelSize):
                node = q.pop(0)

                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

                row.append(node.val)
            
            ans.append(row) if level & 1 else ans.append(row[::-1])
        
        return ans
