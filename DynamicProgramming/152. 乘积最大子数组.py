class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 1: return 0
        f_min = f_max = ans = nums[0]
        for i in range(1, size):
            m, n = f_max, f_min
            f_max = max(n * nums[i], m * nums[i], nums[i])
            f_min = min(n * nums[i], m * nums[i], nums[i])
            ans = max(f_max, ans)

        return ans