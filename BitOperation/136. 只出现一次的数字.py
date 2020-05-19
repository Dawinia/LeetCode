class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return -1
        return reduce(lambda x, y: x ^ y, nums)