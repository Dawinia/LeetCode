class Solution:
    def translateNum(self, num: int) -> int:
        if num < 0: return 0
        if num < 10: return 1

        prev, cur = 0, 1

        sn = str(num)

        for i in range(len(sn)):
            tmp = cur
            if i == 0:
                prev, cur = cur, tmp
                continue
            if 10 <= int(sn[i - 1: i + 1]) <= 25:
                tmp += prev
            prev, cur = cur, tmp
        
        return cur