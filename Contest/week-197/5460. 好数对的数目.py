class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        if not nums: return 0
        s, ans = {}, 0

        for i in nums:
            if i in s:
                ans += s[i]
                s[i] += 1
            else:
                s[i] = 1
        return ans
