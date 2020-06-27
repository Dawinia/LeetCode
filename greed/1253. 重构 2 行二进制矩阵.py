class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if not colsum or upper + lower != sum(colsum): return []

        ans = [[0 for _ in range(len(colsum))] for _ in range(2)]
        for i in range(len(colsum)):
            if colsum[i] == 2:
                ans[0][i] = ans[1][i] = 1
                upper, lower = upper - 1, lower - 1
            elif colsum[i] == 0:
                ans[0][i] = ans[1][i] = 0
            else:
                if upper > lower:
                    ans[0][i] = 1 
                    upper -= 1
                else:
                    ans[1][i] = 1
                    lower -= 1
        return ans if (upper | lower) == 0 else []