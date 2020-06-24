class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        if not nums: return 0
        count, one, size = 0, 0, len(nums)
        step = 31
        while step >= 0:
            flag = False
            for i in range(size):
                one += (nums[i] & 1)
                nums[i] >>= 1
                flag |= nums[i]
            count += one * (size - one)
            if not flag:
                step = 0
            step -= 1
            one = 0
        return count
