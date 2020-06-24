class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if p == ".*":
            return True

        sl, pl = len(s), len(p)
        def match(i: int, j: int) -> bool:
            if i == 0:
                return False
            if p[j - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        f = [[False] * (pl + 1) for _ in range(sl + 1)]
        f[0][0] = True
        for i in range(sl + 1):
            for j in range(1, pl + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2]
                    if match(i, j - 1):
                        f[i][j] |= f[i - 1][j]
                else:
                    if match(i, j):
                        f[i][j] |= f[i - 1][j - 1]
        return f[sl][pl]
