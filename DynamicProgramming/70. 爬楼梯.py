class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        prev, cur = 1, 2

        for i in range(2, n):
            tmp = prev + cur
            prev, cur = cur, tmp
        
        return cur