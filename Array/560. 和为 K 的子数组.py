class Solution:
    def subarraySum(self, nums, k: int) -> int:
        size = len(nums)
        if size < 1:
            return 0
        s, ans, pre = defaultdict(int), 0, 0
        s[0] = 1
        for i in range(size):
            pre += nums[i]

            if pre - k in s:
                ans += s[pre - k]
            s[pre] = s[pre] + 1

        return ans