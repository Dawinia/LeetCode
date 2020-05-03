class Solution:
    def findPoisonedDuration(self, timeSeries, duration: int) -> int:
        size = len(timeSeries)
        if size < 1:
            return 0
        ans = 0
        for i in range(size - 1):
            ans += min(timeSeries[i + 1] - timeSeries[i], duration)
        return ans + duration