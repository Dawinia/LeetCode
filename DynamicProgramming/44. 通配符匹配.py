class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def allStars(st: str, left: int, right: int) -> bool:
            return all(st[i] == '*' for i in range(left, right))
        
        def charMatch(u: str, v: str) -> bool:
            return u == v or v == '?'

        sRight, pRight = len(s), len(p)
        while sRight > 0 and pRight > 0 and p[pRight - 1] != '*':
            if charMatch(s[sRight - 1], p[pRight - 1]):
                sRight -= 1
                pRight -= 1
            else:
                return False
        
        if pRight == 0:
            return sRight == 0
        
        sIndex, pIndex = 0, 0
        sRecord, pRecord = -1, -1
        while sIndex < sRight and pIndex < pRight:
            if p[pIndex] == '*':
                pIndex += 1
                sRecord, pRecord = sIndex, pIndex
            elif charMatch(s[sIndex], p[pIndex]):
                sIndex += 1
                pIndex += 1
            elif sRecord != -1 and sRecord + 1 < sRight:
                sRecord += 1
                sIndex, pIndex = sRecord, pRecord
            else:
                return False

        return allStars(p, pIndex, pRight)
