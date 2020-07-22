class Solution:
    def numSub(self, s: str) -> int:
        if not s: return 0
        mode = 10 ** 9 + 7

        def mul(n):
            return ((n + 1) >> 1) * n if n & 1 else (n >> 1) * (n + 1)

        ans = i = 0
        while i < len(s):
            count = 0
            while i < len(s) and s[i] == '1':
                i += 1
                count += 1
            ans += mul(count) % mode
            i += 1
        return ans