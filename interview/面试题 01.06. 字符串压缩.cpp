class Solution {
public:
    string compressString(string S) {
        int size = S.size();
        int count = 0;
        string ans = "";
        char cur = '.';
        for(int i = 0; i < size; ++i) {
            if(cur != S[i]) {
                if(i != 0) {
                    ans += S[i - 1];
                    ans += to_string(count - 1);
                    count = 0;
                }
                cur = S[i];
                ++count;
            }
            ++count;
        }
        ans += S[size - 1];
        ans += to_string(count - 1);
        if(ans.size() >= size)
            return S;
        return ans;
    }
};