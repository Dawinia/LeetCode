class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 or n == 1:
            return 1
        up = down = result = 1
        if m > n:
            m, n = n, m
        for i in range(1, m + n - 1):
            up = i
            if i < m:
                down = i
            elif i < m + n:
                down = i - m + 1
            result *= up / down
        return int(result + 0.5)


#############################
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(m)] for _ in range(n)]

        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[n - 1][m - 1]