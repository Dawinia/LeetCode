class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        size = len(nums)
        if size < 3:
            return False
        small = mid = float('inf')
        for num in nums:
            if num <= small:
                small = num
            elif num <= mid:
                mid = num
            elif num > mid:
                return True
        return False