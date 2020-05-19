class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        if len(b) == 0:
            return 1
        tmp = b[-1]
        b.pop()
        part1 = self.mypow(a, tmp)
        part2 = self.mypow(self.superPow(a, b),10)
        return (part1 * part2) % 1337

    def mypow(self, a, k):
        if k == 0:
            return 1
        base = 1337
        a %= base
        res = 1
        for i in range(k):
            res *= a
            res %= base
        return res