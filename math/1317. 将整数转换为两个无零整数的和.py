class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        while(True):
            L = random.randint(1,n)
            R = n-L
            if '0' not in str(L) and '0' not in str(R):
                return [L,R]