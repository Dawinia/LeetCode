class Solution:
    def search(self, nums, target: int) -> int:
        size = len(nums)
        if size < 1 or size < 2 and nums[0] != target:
            return -1

        l, h = 0, size - 1
        while l < h:
            mid = l + ((h - l) >> 1)
            if nums[mid] == target:
                return mid
            if nums[mid] >= nums[l]:
                if nums[l] <= target < nums[mid]:
                    h = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[h]:
                    l = mid + 1
                else:
                    h = mid - 1
        return l if nums[l] == target else -1 