class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int size = words.size();
        if(size == 1)
            return words[0].length() + 1;
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        for(int i = 0; i < size; ++i) {
            if (i + 1 >= size || words[i + 1].find(words[i]) != 0)
                ans += words[i].length() + 1;
        }
        return ans;
    }
};