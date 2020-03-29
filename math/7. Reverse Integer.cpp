class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        int temp = x;
        while(x != 0) {
            int num = x % 10;
            if(num == 0 && temp == x) {
                x /= 10;
                continue;
            }
            ans *= 10;
            ans += num;
            x /= 10;
        }
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};