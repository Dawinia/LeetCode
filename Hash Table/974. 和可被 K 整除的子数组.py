class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        d = {0: 1}

        t = ans = 0
        for e in A:
            t += e
            m = t % K
            prev = d.get(m, 0)
            ans += prev
            d[m] = prev + 1
        return ans