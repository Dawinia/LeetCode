class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid: return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if m == 1: return 0 if sum(obstacleGrid[0]) >= 1 else 1

        dp = [0 for _ in range(n)]

        dp[0] = 1
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                    continue
                if j - 1 >= 0 and obstacleGrid[i][j - 1] == 0:
                    dp[j] += dp[j - 1]
        return dp[-1]