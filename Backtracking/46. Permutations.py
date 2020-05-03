class Solution:
    def permute(self, nums):
        if len(nums) < 1:
            return [[]]
        ans = []

        def dfs(one):
            if len(one) == len(nums):
                ans.append(one)
                return
            for i in nums:
                if i in one:
                    continue
                dfs(one + [i])

        for i in nums:
            dfs([i])
        return ans