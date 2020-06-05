class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        ans = 0
        for i in range(3):
            ans += guess[i] == answer[i]
        return ans
