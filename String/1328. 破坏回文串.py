class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if not palindrome or len(palindrome) == 1: return ""
        size = len(palindrome)
        pl = list(palindrome)
        for i in range(size // 2 + 1):
            if palindrome[i] == 'a' or (size & 1 and i == size // 2):
                continue
            return palindrome.replace(palindrome[i], 'a', 1)
        return palindrome[:-1] + 'b'