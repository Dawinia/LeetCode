class Node:
    def __init__(self, val):
        self.val = val
        self.is_end = False
        self.next = {}


class Solution:
    def removeSubfolders(self, folder):
        size = len(folder)
        if size < 1: return []
        ans, root = [], Node('/')
        for f in folder:
            node = root
            same, files = True, f.split('/')
            for i, sub in enumerate(files[1:]):
                if sub not in node.next:
                    same = False
                    node.next[sub] = Node(sub)
                node = node.next[sub]
                if same and not node.next:
                    break
                if same and i == len(files) - 2:
                    node.next = {}

        def dfs(root, path):
            nonlocal ans
            if not root.next:
                ans.append(path)
            for v in root.next.values():
                dfs(v, path + f'/{v.val}')

        dfs(root, "")
        return ans