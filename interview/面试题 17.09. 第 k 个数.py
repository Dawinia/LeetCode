class Solution:
    def getKthMagicNumber(self, k: int) -> int:
        if k < 2: return k
        i3 = i5 = i7 = 0

        dp = [1] * k 
        for i in range(1, k):
            dp[i] = min(dp[i3] * 3, dp[i5] * 5, dp[i7] * 7)
            if dp[i] == dp[i3] * 3: i3 += 1
            if dp[i] == dp[i5] * 5: i5 += 1
            if dp[i] == dp[i7] * 7: i7 += 1

        return dp[-1]