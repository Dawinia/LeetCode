# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        s, ans = [], []
        while len(s) or root:
            if root:
                ans.append(root.val)
                s.append(root)
                root = root.left
            else:
                root = s.pop().right
        return ans