# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(p, q):
            queue = []
            queue.append(p)
            queue.append(q)

            while queue:
                u = queue.pop(0)
                v = queue.pop(0)

                if not u and not v: continue
                if not u or not v or u.val != v.val: return False

                queue.append(u.left)
                queue.append(v.right)
                queue.append(u.right)
                queue.append(v.left)
            return True
        
        return check(root, root)