class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle or not triangle[0]: return 0

        m, n = len(triangle), len(triangle[-1])

        dp = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m - 1, -1, -1):
            n -= 1
            for j in range(n + 1):
                if i == m - 1:
                    dp[i][j] = triangle[i][j]
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]
        return dp[0][0]



###############################################################


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle or not triangle[0]: return 0

        n = len(triangle)

        dp, tmp = [0 for _ in range(n)], 0

        for i in range(n - 1, -1, -1):
            if i < n - 1:
                tmp = dp[i + 1]
            for j in range(i, -1, -1):
                if i == n - 1:
                    dp[j] = triangle[i][j]
                else:
                    s = dp[j]
                    dp[j] = min(tmp, dp[j]) + triangle[i][j]
                    tmp = s
        return dp[0]



#####################################################


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle or not triangle[0]: return 0

        n = len(triangle)

        dp, tmp = triangle[-1], 0

        for i in range(n - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = min(dp[j + 1], dp[j]) + triangle[i][j]
        return dp[0]