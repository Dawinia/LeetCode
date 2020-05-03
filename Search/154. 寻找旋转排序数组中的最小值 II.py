class Solution:
    def findMin(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 1:
            return -1
        left, right = 0, size - 1

        while left < right:
            mid = left + ((right - left) >> 1)
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return nums[left]