class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        if not S: return []

        last = {c: i for i, c in enumerate(S)}


        ans = []
        start = j = 0
        for i in range(len(S)):
            j = max(j, last[S[i]])
            if j == i:
                ans.append(j - start + 1)
                start = i + 1
        return ans

