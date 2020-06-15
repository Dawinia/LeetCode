class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        if not nums: return []
        n = len(nums)
        e, f, b, d = n * (n + 1) >> 1, 0, 0, 0
        for i in nums:
            if (b >> (i - 1)) & 1:
                d = i
            b |= (1 << (i - 1))
            f += i
        return [d, e - f + d]