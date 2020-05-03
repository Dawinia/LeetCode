class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def get_next(version, n, p):
            if p > n - 1:
                return 0, p
            p_end = p
            while p_end < n and version[p_end] != '.':
                p_end += 1
            i = int(version[p: p_end]) if p_end != n - 1 else 0

            return i, p_end + 1

        i, j = 0, 0
        s1, s2 = len(version1), len(version2)

        while i < s1 or j < s2:
            n1, i = get_next(version1, s1, i)
            n2, j = get_next(version2, s2, j)
            if n1 > n2:
                return 1
            elif n1 < n2:
                return -1
        return 0
