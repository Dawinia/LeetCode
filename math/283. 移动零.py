class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums: return

        size = len(nums)
        j = 0
        for i in range(size):
            if nums[i] != 0:
                nums[j], nums[i] = nums[i], nums[j]
                j += 1