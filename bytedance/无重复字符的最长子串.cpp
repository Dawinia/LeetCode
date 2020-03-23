class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charMap;   
        int size = s.length();
        int ans = 0;
        int left = 0;
        for(int i = 0; i < size; ++i) {
            if(charMap[s[i]] == 0 || charMap[s[i]] < left) {
                ans = max(ans, i - left + 1);
            }
            else {
                left = charMap[s[i]];
            }
            charMap[s[i]] = i + 1;
        }
        return ans;
    }
};