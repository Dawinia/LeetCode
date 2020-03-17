class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> charMap;
        map<char, int> wordMap;
        int ans = 0, len = 0;
        bool ok = true;
        for(auto ch: chars) {
            ++charMap[ch];
        }
        for(auto word: words) {
            len = 0;
            wordMap.erase(wordMap.begin(), wordMap.end());
            ok = true;
            for(auto ch: word) {
                ++wordMap[ch];
                ++len;
                if(wordMap[ch] > charMap[ch]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans += len;
            }
        }
        return ans;
    }
};