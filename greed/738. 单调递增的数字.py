class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        if N < 10:
            return N
        s = str(N)
        i = 0
        start = -1
        while i < len(s) - 1:
            if s[i] > s[i + 1]:
                if start != -1 and s[i] != s[start]:
                    start = -1
                break
            elif s[i] == s[i + 1]:
                start = s.find(s[i])
            i += 1
        if start != -1:
            i = start
        if i == len(s) - 1:
            return N
        pos = 10 ** (len(s) - i - 1)
        high = N // pos
        return high * pos - 1
