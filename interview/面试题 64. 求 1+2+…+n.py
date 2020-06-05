class Solution:
    def sumNums(self, n: int) -> int:
        ans = 0
        def get_sum(n):
            nonlocal ans
            ans += n
            return n and get_sum(n - 1)
        get_sum(n)
        return ans