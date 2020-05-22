class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        size = len(A)
        if size < 3:
            return 0
        
        i, mid, j = 0, 1, 2
        ans = 0
        while j < size:
            diff = A[mid] - A[i]
            while j < size and diff == A[j] - A[mid]:
                j, mid = j + 1, j
            ans += ((j - i - 1) * (j - i - 2) // 2)
            i, mid, j = j - 1, j, j + 1
        return ans