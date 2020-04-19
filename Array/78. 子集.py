import itertools
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        size = len(nums)
        if size < 1:
            return []
        ans = []
        for i in range(size + 1):
            for item in itertools.combinations(nums, i):
                ans.append(list(item))
        return ans
        