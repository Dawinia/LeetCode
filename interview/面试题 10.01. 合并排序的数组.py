class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i, j, k = m - 1, n - 1, m + n - 1

        while j >= 0:
            if i < 0 or A[i] <= B[j]:
                A[k] = B[j]
                j -= 1
            else:
                A[k] = A[i]
                i -= 1
            k -= 1