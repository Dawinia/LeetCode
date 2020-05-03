class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        base = 1900
        size = len(birth)
        ans = i = 0
        table = [0] * 101
        while i < size:
            b, d = birth[i] - base, death[i] - base
            for j in range(b, d + 1):
                table[j] += 1
            i += 1

        return table.index(max(table)) + base



