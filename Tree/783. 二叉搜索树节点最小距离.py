# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        if not root: return -1

        nodes, node = [], root
        ans, cur = float('inf'), float('-inf')
        while node or nodes:
            while node:
                nodes.append(node)
                node = node.left
            node = nodes.pop()
            ans = min(ans, node.val - cur)
            cur = node.val
            node = node.right
        
        return ans