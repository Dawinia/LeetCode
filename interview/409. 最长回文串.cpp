class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());
        int count = 0, ans = 0, size = s.length();
        if(size == 0)
            return 0;
        int i = 0;
        while(i < size) {
            int next = s.rfind(s[i]);
            if((next - i + 1) % 2 != 0)
                ans += 1;
            i = next + 1;
        }
        return ans == 0 ? size : size -ans + 1;
    }
};