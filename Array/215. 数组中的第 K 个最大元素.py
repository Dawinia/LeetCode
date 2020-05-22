class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, l, r):
            pivot, i = nums[r], l - 1

            for j in range(l, r):
                if nums[j] <= pivot:
                    i += 1
                    nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1], nums[r] = nums[r], nums[i + 1]
            return i + 1

        size = len(nums)
        l, r = 0, size - 1
        target = size - k
        while True:
            q = partition(nums, l, r)
            if q == target:
                return nums[q]
            elif q < target:
                l = q + 1
            else:
                r = q - 1