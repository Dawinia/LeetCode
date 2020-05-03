import bisect
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 2:
            return 0
        p = []
        ans = 0
        for num in nums:
            ans += len(p) - bisect.bisect(p, num)
            bisect.insort(p, num)
        return ans