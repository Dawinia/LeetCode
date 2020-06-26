# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.nodes = []
        self._create(root)

    def _create(self, root):
        while root:
            self.nodes.append(root)
            root = root.left


    def next(self) -> int:
        """
        @return the next smallest number
        """
        if not self.nodes:
            return -1
        node = self.nodes.pop()
        if node.right:
            self._create(node.right)
        return node.val


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.nodes) > 0



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()