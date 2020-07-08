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

##########################################

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        size = len(s)
        if size < 2:
            return 0
        dp, ans = [-1], 0
        for i in range(size):
            if s[i] == '(':
                dp.append(i)
            else:
                dp.pop()
                if not dp:
                    dp.append(i)
                else:
                    ans = max(ans, i - dp[-1])
        return ans

###################################

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        size = len(s)
        if size < 2:
            return 0
        left = right = ans = 0

        for c in s:
            if c == '(':
                left += 1
            else:
                right += 1
            if left == right:
                ans = max(ans, left + right)
            elif right > left:
                left = right = 0
        left = right = 0
        for i in range(size - 1, -1, -1):
            if s[i] == '(':
                left += 1
            else:
                right += 1
            if left == right:
                ans = max(ans, left + right)
            elif left > right:
                left = right = 0

        return ans