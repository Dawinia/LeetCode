# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        queue, ans = [root], "["
        while queue and any(queue):
            node = queue.pop(0)
            if node:
                ans += str(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                ans += "none"
            ans += ','
        return ans[:-1] + "]"


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        data = data[1: -1].split(',')
        head = tmp = TreeNode(data[0])
        index, size = [(tmp, 0)], len(data)
        i = 1
        while i < size:
            node, j = index.pop(0)
            if i < size and data[i] != 'none':
                node.left = left = TreeNode(data[i])
                index.append((left, j + 1))
            else:
                node.left = None
            i += 1
            if i < size and data[i] != 'none':
                node.right = right = TreeNode(data[i])
                index.append((right, j + 1))
            else:
                node.right = None
            i += 1

        return head


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))