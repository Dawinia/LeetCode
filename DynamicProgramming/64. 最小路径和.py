class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid: return -1
        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if i == 0 and j != 0:
                    grid[i][j] = grid[i][j - 1] + grid[i][j]
                elif j == 0 and i != 0:
                    grid[i][j] = grid[i - 1][j] + grid[i][j]
                elif i * j > 0:
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j]
        
        return grid[-1][-1]