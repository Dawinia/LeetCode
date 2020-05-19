class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a_real, a_com = a.split('+')
        b_real, b_com = b.split('+')
        a_com, b_com = a_com[:-1], b_com[:-1]

        ans_real = int(a_real) * int(b_real) - (int(a_com) * int(b_com))
        ans_com = int(a_real) * int(b_com) + int(b_real) * int(a_com)

        return str(ans_real) + '+' + str(ans_com) + 'i'