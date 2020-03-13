class Solution {
public:
    string generateTheString(int n) {
        if(n % 2 == 0) {
            string ans = "a";
            for(int i = 0; i < n - 1; ++i) {
                ans += "b";
            }
            return ans;
        }
        else {
            string ans = "a";
            for(int i = 0; i < n - 1; ++i) {
                ans += "a";
            }
            return ans;
        }
    }
};