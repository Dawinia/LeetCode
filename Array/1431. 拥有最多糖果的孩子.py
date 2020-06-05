class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        size = len(candies)
        if size < 1:
            return []
        m, ans = max(candies), [False] * size
        for i, e in enumerate(candies):
            ans[i] = e + extraCandies >= m
        return ans