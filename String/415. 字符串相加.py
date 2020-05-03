class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        s1, s2 = len(num1) - 1, len(num2) - 1
        ans, cb = "", 0
        while s1 >= 0 or s2 >= 0:
            n1 = int(num1[s1]) if s1 >= 0 else 0
            n2 = int(num2[s2]) if s2 >= 0 else 0
            d = n1 + n2 + cb
            cb = d // 10
            d %= 10
            ans += str(d)
            s1, s2 = s1 - 1, s2 - 1
        if cb != 0:
            ans += str(cb)
        return ans[::-1]