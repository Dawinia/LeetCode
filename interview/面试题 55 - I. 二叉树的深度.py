# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def getDepth(head):
            if head is None:
                return 0
            return 1 + max(getDepth(head.left), getDepth(head.right))
        
        return getDepth(root)