class Solution:
    def cuttingRope(self, n: int) -> int:
        def get_mul(l, a):
            ans = 1
            while l > 0:
                sub = l // a
                ans *= sub
                a -= 1
                l -= sub
            return ans

        m, ans = n // 2, 0
        for i in range(2, m + 1):
            ans = max(ans, get_mul(n, i))
        return ans if ans != 0 else n - 1