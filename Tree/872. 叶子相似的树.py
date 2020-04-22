# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.leaf = []

    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        if root1 is None or root2 is None:
            return False
        self.getLeaf(root1)
        self.leaf.append('#')
        self.getLeaf(root2)
        pos = self.leaf.index('#')
        print(self.leaf)
        i = 0
        while i < pos:
            if i + pos + 1 < len(self.leaf) and self.leaf[i] != self.leaf[i + pos + 1]:
                return False
            i += 1
        return i + pos + 1 == len(self.leaf)
        
    def getLeaf(self, root: TreeNode):
        if root is None:
            return
        if root.left is None and root.right is None:
            self.leaf.append(root.val)
            return
        self.getLeaf(root.left)
        self.getLeaf(root.right)

