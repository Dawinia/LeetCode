# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = -1000000000
    
    def maxPathSum(self, root: TreeNode) -> int:
        self.traverse(root)
        return self.ans
    
    def traverse(self, root):
        if not root:
            return 0
        left = max(0, self.traverse(root.left))
        right = max(0, self.traverse(root.right))
        self.ans = max(self.ans, left + right + root.val)
        return max(left, right) + root.val
