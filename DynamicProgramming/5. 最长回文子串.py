class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length < 2:
            return s
        dp = [[False for _ in range(length)] for _ in range(length)]

        for i in range(length):
            dp[i][i] = True
        
        maxLen, start = 1, 0
        for j in range(1, length):
            for i in range(j):
                if s[i] == s[j]:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = False
                
                if dp[i][j]:
                    if maxLen < j - i + 1:
                        maxLen, start = j - i + 1, i
                        
        return s[start: start + maxLen]
