# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        cur = float('-inf')
        q = []
        while len(q) or root:
            if root:
                q.append(root)
                root = root.left
            else:
                root = q.pop()
                if root.val > cur:
                    cur = root.val
                else:
                    return False
                root = root.right
        
        return True