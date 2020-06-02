class Solution:
    def longestValidParentheses(self, s: str) -> int:
        size = len(s)
        if size < 2:
            return 0
        dp, ans = [0] * size, 0
        for i, c in enumerate(s):
            if c == ')':
                if i > 1 and s[i - 1] == '(':
                    dp[i] = dp[i - 2] + 2
                else:
                    j = i - dp[i - 1] - 1
                    if j >= 0 and s[j] == '(':
                        dp[i] = dp[i - 1] + 2 + dp[j - 1]
            ans = max(ans, dp[i])
        return ans