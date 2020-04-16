class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        e = (A & 0xffffffff) ^ (B & 0xffffffff)
        count = 0
        while e:
            e = e & (e - 1)
            count += 1
        return count