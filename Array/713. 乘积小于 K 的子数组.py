class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        size = len(nums)
        if size < 1 or k <= 1: return 0
        ans, sub_value, left = 0, 1, 0
        for right, value in enumerate(nums):
            sub_value *= value
            while sub_value >= k:
                sub_value /= nums[left]
                left += 1
            ans += right - left + 1
        return ans