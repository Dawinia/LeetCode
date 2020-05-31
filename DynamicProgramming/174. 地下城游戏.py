class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n = len(dungeon)
        if n < 1: return -1
        m = len(dungeon[0])

        dp = [float('inf')] * (n + 1)
        dp[n - 1] = 1

        for j in range(m)[::-1]:
            for i in range(n)[::-1]:
                dp[i] = min(dp[i], dp[i + 1]) - dungeon[i][j]
                dp[i] = max(1, dp[i])


        return dp[0]