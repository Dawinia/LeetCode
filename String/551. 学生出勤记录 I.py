class Solution:
    def checkRecord(self, s: str) -> bool:
        return s.find('A') == s.rfind('A') and 'LLL' not in s