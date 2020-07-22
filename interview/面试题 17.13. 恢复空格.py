class Solution:
    def respace(self, dictionary, sentence: str) -> int:
        if not dictionary or not sentence: return 0

        RK, P, size = 29, 1 << 31 - 1, len(sentence)

        def get_hash(s):
            h = 0
            for i in range(len(s) - 1, -1, -1):
                num = ord(s[i]) - 96
                h = h * RK + num
                h %= P
            return h

        hash_set = set()
        for word in dictionary:
            hash_set.add(get_hash(word))
        f = [0] * (size + 1)
        for i in range(1, size + 1):
            f[i] = f[i - 1] + 1
            h = 0
            for j in range(i, 0, -1):
                num = ord(sentence[j - 1]) - 96
                h = h * RK + num
                h %= P
                if h in hash_set:
                    f[i] = min(f[i], f[j - 1])
        return f[-1]