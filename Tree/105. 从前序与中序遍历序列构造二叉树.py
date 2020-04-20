# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        def createTree(preorder, inorder, pstart, pend, istart, iend):
            if pstart > pend:
                return None
            node = TreeNode(preorder[pstart])

            pos = istart
            for i in range(istart, iend + 1):
                if inorder[i] == node.val:
                    pos = i
                    break
            node.left = createTree(preorder, inorder, pstart + 1, pstart + pos - istart, istart, pos - 1)
            node.right = createTree(preorder, inorder, pend - iend + pos + 1, pend, pos + 1, iend)
            return node
        
        return createTree(preorder, inorder, 0, len(preorder) - 1, 0, len(inorder) - 1)