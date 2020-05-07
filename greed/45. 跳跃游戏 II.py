class Solution:
    def jump(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 2:
            return 0
        ans = 0

        longest = border = 0
        for i in range(size - 1):
            longest = max(longest, i + nums[i])
            if i == border:
                border = longest
                ans += 1
        return ans
