class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums: return 0
        l, r = 0, len(nums)

        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid
            elif nums[mid] < target:
                l = mid + 1
        return l