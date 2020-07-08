class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        size = len(nums)
        if size < 4: return max(nums)

        def rob_sub(num):
            prev = cur = 0
            for c in num:
                tmp = max(cur, prev + c)
                prev, cur = cur, tmp
            return cur
        return max(rob_sub(nums[1:]), rob_sub(nums[:-1]))