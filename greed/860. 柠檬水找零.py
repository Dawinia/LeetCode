class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        size = len(bills)
        if size < 1: return False
        five = ten = 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                if five == 0: return False
                ten, five = ten + 1, five - 1
            else:
                if ten >= 1 and five >= 1:
                    ten, five = ten - 1, five - 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True