class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 1:
            return 1
        for i in range(n):
            while 0 < nums[i] < n and nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                nums[i], nums[tmp - 1] = nums[tmp - 1], nums[i]
        for i, e in enumerate(nums):
            if e != i + 1:
                return i + 1
        return n + 1