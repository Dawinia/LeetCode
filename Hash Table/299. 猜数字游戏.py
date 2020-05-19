class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = sum(s==g for s,g in zip(secret,guess))
        B = sum((collections.Counter(secret)&collections.Counter(guess)).values())-A
        return "{A}A{B}B".format(A=A,B=B)