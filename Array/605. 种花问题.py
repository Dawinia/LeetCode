class Solution:
    def canPlaceFlowers(self, flowerbed, n: int) -> bool:
        size, i = len(flowerbed), 0
        cnt = 0

        while i < size:
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == size - 1 or flowerbed[i + 1] == 0):
                flowerbed[i] = 1
                cnt += 1
            if cnt >= n:
                return True
            i += 1
        return False