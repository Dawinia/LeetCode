# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        s, ans = [], []
        while len(s) or root:
            if root:
                s.append(root)
                root = root.left
            else:
                node = s.pop()
                ans.append(node.val)
                root = node.right
        return ans