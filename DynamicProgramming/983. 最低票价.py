class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        s1, s2 = len(days), len(costs)
        if not s1 or not s2:
            return 0
        dp = [0] * 367
        d = [1, 7, 30]
        dayset = set(days)

        for i in range(days[-1], 0, -1):
            if i > 365:
                dp[i] = 0
                continue
            if i in dayset:
                dp[i] = min(dp[i + d] + c for c, d in zip(costs, d) if i + d < 367)
            else:
                dp[i] = dp[i + 1]
        
        return dp[1]