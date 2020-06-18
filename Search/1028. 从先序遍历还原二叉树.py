# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        if not S: return None

        def get_num(i: int) -> tuple:
            num = 0
            while i < len(S) and S[i] != '-':
                num *= 10
                num += int(S[i])
                i += 1
            return i, num

        i, num = get_num(0)
        root = node = TreeNode(num)
        nodes = [(0, node)]
        while i < len(S):
            level, isr = 0, False
            while i < len(S) and S[i] == '-':
                level += 1
                i += 1
            
            i, num = get_num(i)
            node = TreeNode(num)
            while nodes and nodes[-1][0] >= level:
                isr = True
                nodes.pop()
            if isr:
                nodes[-1][1].right = node
            else:
                nodes[-1][1].left = node
            nodes.append((level, node))
        return root