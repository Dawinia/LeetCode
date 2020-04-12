class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        sl = s.strip().split(' ')
        sl = [word for word in sl if len(word)]
        sl.reverse()
        return " ".join(sl)