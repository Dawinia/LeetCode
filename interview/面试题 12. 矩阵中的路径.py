# class Solution:
#     def exist(self, board, word: str) -> bool:

#         directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

#         n = len(board)
#         if n < 1:
#             return False
#         m = len(board[0])
#         s = len(word)

#         visited = []
#         flag = False

#         def back(pos, index):
#             nonlocal flag
#             if index == s:
#                 flag = True
#                 return
#             i, j = pos
#             for di, dj in directions:
#                 ni, nj = i + di, j + dj
#                 if 0 <= ni < n and 0 <= nj < m and (ni, nj) not in visited and board[ni][nj] == word[index]:
#                     visited.append((ni, nj))
#                     back((ni, nj), index + 1)
#                     if flag:
#                         return
#             visited.pop()

#         for i, row in enumerate(board):
#             for j, c in enumerate(row):
#                 if c == word[0]:
#                     visited.append((i, j))
#                     back((i, j), 1)
#                     if flag:
#                         return True
#         return flag
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, k):
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[k]: return False
            if k == len(word) - 1: return True
            tmp, board[i][j] = board[i][j], '/'
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k + 1) or dfs(i, j + 1, k + 1) or dfs(i, j - 1, k + 1)
            board[i][j] = tmp
            return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0): return True
        return False