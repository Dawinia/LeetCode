class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N < 1 or K < 1 or K > (1 << (N - 1)):
            return -1
        if K == 1: return 0
        count = 0
        while N > 1:
            total = (1 << (N - 2))
            if K > total:
                count += 1
                K -= total
            N -= 1

        return 1 if count & 1 else 0

####################################

class Solution:
    def kthGrammar(self, N, K):
        return bin(K - 1).count('1') % 2
