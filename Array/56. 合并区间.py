class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        size = len(intervals)
        if size < 2:
            return intervals
        intervals.sort()
        ans = [intervals[0]]
        for i in range(1, size):
            inter = ans[-1]
            if inter[1] >= intervals[i][0]:
                ans.pop()
                ans.append([inter[0], intervals[i][1] if inter[1] < intervals[i][1] else inter[1]])
            else:
                ans.append(intervals[i])
        return ans


