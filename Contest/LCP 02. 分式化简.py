class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        if not cont:
            return [0, 1]
        size = len(cont) - 1
        up, down = 1, cont[-1]
        while size > 0:
            up, down = down, up
            down += cont[size - 1] * up
            size -= 1
        return [down, up]