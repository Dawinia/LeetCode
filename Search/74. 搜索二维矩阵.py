class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m < 1: return False
        n = len(matrix[0])
        if n < 1: return False
        if target < matrix[0][0] or target > matrix[m - 1][n - 1]: return False

        l, r = 0, m * n - 1
        while l <= r:
            mid = l + (r - l) // 2
            num = matrix[mid // n][mid % n]
            if num == target:
                return True
            elif num > target:
                r -= 1
            elif num < target:
                l += 1
        
        return False