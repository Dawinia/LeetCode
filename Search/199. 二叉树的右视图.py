# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        queue = []
        ans = []
        queue.append(root)
        while len(queue):
            cnt = len(queue)
            i = 0
            while i < cnt:
                node = queue.pop(0)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                i += 1
            ans.append(node.val)
        return ans


