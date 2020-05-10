class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = None

        def dfs(node, p, q):
            nonlocal ans
            if not node:
                return False
            lson = dfs(node.left, p, q)
            rson = dfs(node.right, p, q)
            if (lson and rson) or ((node.val == p.val or node.val == q.val) and (lson or rson)):
                ans = node
            return lson or rson or (node.val == p.val or node.val == q.val)

        dfs(root, p, q)
        return ans