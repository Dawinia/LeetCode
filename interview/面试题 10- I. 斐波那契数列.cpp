class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        int ans, f = 0, s = 1;
        for(int i = 2; i <= n; ++i) {
            ans = (f + s) % 1000000007;
            f = s % 1000000007;
            s = ans;
        }
        return ans;
    }
};