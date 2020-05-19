class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        size = len(s)
        if size < 1 or n < 1:
            return ""
        return s[n:] + s[0: n]