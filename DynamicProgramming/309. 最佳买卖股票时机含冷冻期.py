class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0

        n = len(prices)
        dp = [[0 for _ in range(3)] for _ in range(n)]

        dp[0][0] = -prices[0]

        for i in range(1, n):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i])
            dp[i][1] = dp[i - 1][0] + prices[i]
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1])
        return max(dp[-1][1], dp[-1][2])

###################################################

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0

        n = len(prices)
        if n < 3:
            return max(0, prices[-1] - prices[0])
        dp = [[0 for _ in range(2)] for _ in range(n)]

        dp[0][0], dp[0][1] = 0, -prices[0]
        dp[1][0], dp[1][1] = max(dp[0][0], dp[0][1] + prices[1]), max(dp[0][0] - prices[1], dp[0][1])
        for i in range(2, n):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i])
        return dp[-1][0]