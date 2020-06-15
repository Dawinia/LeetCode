class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums: return []

        nums.sort()
        size = len(nums)
        ans = []
        if nums[0] <= 0 and nums[-1] >= 0:
            for i in range(size - 2):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                if nums[i] > 0:
                    break
                left, right = i + 1, size - 1
                while left < right:
                    temp = nums[i] + nums[left] + nums[right]
                    if temp == 0:
                        ans.append([nums[i], nums[left], nums[right]])
                    if temp > 0:
                        o, right = nums[right], right - 1
                        while left < right and o == nums[right]:
                            right -= 1
                    else:
                        o, left = nums[left], left + 1
                        while left < right and o == nums[left]:
                            left += 1
        return ans