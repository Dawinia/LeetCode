class Solution:
    def toGoatLatin(self, S: str) -> str:
        sl = S.split(' ')
        for i in range(len(sl)):
            if sl[i][0].lower() not in ['a', 'e', 'i', 'o', 'u']:
                sl[i] = sl[i][1:] + sl[i][0]
            sl[i] += 'ma' + 'a' * (i + 1)
        return ' '.join(sl)