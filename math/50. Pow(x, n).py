class Solution:
    def myPow(self, x: float, n: int) -> float:
        m = abs(n)
        ans = 1
        while m > 0:
            if m & 1:
                ans *= x
            x *= x
            m >>= 1
        return ans if n > 0 else 1 / ans
