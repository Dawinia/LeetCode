class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        if not a: return []

        size = len(a)
        ans = [1] * size
        for i in range(1, size):
            ans[i] = ans[i - 1] * a[i - 1]
        back = 1
        for i in range(size - 2, -1, -1):
            back *= a[i + 1]
            ans[i] *= back
        return ans
