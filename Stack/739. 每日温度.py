class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        if not T:
            return []
        size = len(T)
        s = [0]
        ans = [0] * size
        for i in range(1, size):
            while s and T[i] > T[s[-1]]:
                j = s.pop()
                ans[j] = i - j
            s.append(i)
        return ans