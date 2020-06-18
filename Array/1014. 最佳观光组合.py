class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        if not A: return -1

        prev, ans = A[0], 0

        for i in range(1, len(A)):
            prev = max(A[i] + A[i - 1] - 1, prev + A[i] - A[i - 1] - 1)
            ans = max(ans, prev)
        return ans

###########################################################

class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        if not A: return -1

        mx, ans = A[0], 0

        for j in range(1, len(A)):
            ans = max(ans, mx + A[j] - j)
            mx = max(mx, A[j] + j)

        return ans