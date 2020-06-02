class Solution:
    def rob(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 1: return 0
        if size < 2: return nums[0]

        prev = cur = 0
        for e in nums:
            tmp = max(cur, prev + e)
            prev, cur = cur, tmp
        return cur