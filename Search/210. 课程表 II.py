class Solution:
    def findOrder(self, numCourses: int, prerequisites):
        if numCourses < 1:
            return []
        elif numCourses < 2:
            return [0]
        ans = []
        pd = defaultdict(list)
        flag = [-1 for _ in range(numCourses)]
        for k, v in prerequisites:
            pd[v].append(k)

        has_cycle = False

        def dfs(node):
            nonlocal has_cycle
            if has_cycle:
                return

            flag[node] = 0

            if node in pd:
                for an in pd[node]:
                    if flag[an] == -1:
                        dfs(an)
                    elif flag[an] == 0:
                        has_cycle = True
            flag[node] = 1
            ans.append(node)

        for node in range(numCourses):
            if flag[node] == -1:
                dfs(node)
        return ans[::-1] if not has_cycle else []