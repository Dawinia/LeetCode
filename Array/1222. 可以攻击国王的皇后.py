class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        directions = [[0,1],[0,-1],[1,0],[-1,0],[1,1],[1,-1],[-1,1],[-1,-1]]
        ans = []
        queens = {(i, j) for i, j in queens}
        for d in directions:
            nx = king[0] + d[0]
            ny = king[1] + d[1]
            while 0 <= nx < 8 and 0 <= ny < 8:
                if (nx, ny) in queens:
                    ans.append([nx, ny])
                    break
                else:
                    nx += d[0]
                    ny += d[1]
        return ans
