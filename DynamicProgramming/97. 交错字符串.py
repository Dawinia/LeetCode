class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1), len(s2), len(s3)

        if l3 != l1 + l2: return False
        dp = [[False for _ in range(l2 + 1)] for _ in range(l1 + 1)]
        dp[0][0] = True
        for i in range(l1 + 1):
            for j in range(l2 + 1):
                p = i + j - 1
                if i > 0:
                    dp[i][j] |= (dp[i - 1][j] & (s1[i - 1] == s3[p]))
                if j > 0:
                    dp[i][j] |= (dp[i][j - 1] & (s2[j - 1] == s3[p]))
        return dp[l1][l2]


#################################################


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1), len(s2), len(s3)

        if l3 != l1 + l2: return False
        dp = [False for _ in range(l2 + 1)]
        dp[0] = True
        for i in range(l1 + 1):
            for j in range(l2 + 1):
                p = i + j - 1
                if i > 0:
                    dp[j] &= (s1[i - 1] == s3[p])
                if j > 0:
                    dp[j] |= (dp[j - 1] & (s2[j - 1] == s3[p]))
        return dp[l2]