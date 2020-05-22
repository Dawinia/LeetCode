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
#####################################
class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size < 2:
            return s

        t = "#"
        for i in range(size):
            t += s[i]
            t += "#"
        t_len = 2 * size + 1

        p = [0 for _ in range(t_len)]

        max_right = 0
        center = 0

        max_len = 1
        start = 1

        for i in range(t_len):
            if i < max_right:
                mirror = 2 * center - i
                p[i] = min(max_right - i, p[mirror])

            left = i - (1 + p[i])
            right = i + (1 + p[i])

            while left >= 0 and right < t_len and t[left] == t[right]:
                p[i] += 1
                left -= 1
                right += 1

            if i + p[i] > max_right:
                max_right = i + p[i]
                center = i

            if p[i] > max_len:
                max_len = p[i]
                start = (i - max_len) // 2
        return s[start: start + max_len]