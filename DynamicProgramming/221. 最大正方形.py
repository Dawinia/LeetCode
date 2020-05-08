class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        if n < 1: return 0
        m = len(matrix[0])
        if m < 1: return 0

        dp = [[0] * m for _ in range(n)]
        side = 0

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
                
                    side = max(side, dp[i][j])
        
        return side ** 2