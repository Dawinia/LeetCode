class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        if not graph: return True

        def bfs(i):
            color[i], q = 1, []
            q.append(i)
            while len(q) > 0:
                f = q.pop(0)
                for t in graph[f]:
                    if color[t] == 0:
                        q.append(t)
                        color[t] = -color[f]
                    if color[t] == color[f]:
                        return False
            return True

        n = len(graph)
        color = [0] * n

        for i in range(n):
            if color[i] == 0 and not bfs(i):
                return False
        return True