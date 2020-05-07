class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        s = set()
        for i in range(20):
            for j in range(20):
                num = x ** i + y ** j
                if num > bound:
                    continue
                s.add(num)
        return list(s)
