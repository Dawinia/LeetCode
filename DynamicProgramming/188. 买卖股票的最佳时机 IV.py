class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        def maxProfit_inf(prices: List[int]) -> int:
            res = 0
            for i in range(1, len(prices)):
                if prices[i] > prices[i-1]:
                    res += prices[i] - prices[i-1]
            return res
        size = len(prices)
        if size < 1:
            return 0
        if k > size / 2:
            return maxProfit_inf(prices)
        dp = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(size)]

        for i in range(size):
            for j in range(k, 0, -1):
                if i - 1 == -1:
                    dp[i][j][0] = 0
                    dp[i][j][1] = -prices[i]
                    continue
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])

        return dp[size - 1][k][0]