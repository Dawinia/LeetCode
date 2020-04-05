class Solution {
public:
    int myAtoi(string str) {
        char first = ' ';
        long ans = 0;
        bool isNeg = false;
        int size = str.length();
        int count = 0;
        for(int i = 0; i < size; ++i) {
            if((str[i] <= '9' && str[i] >= '0')) {
                first = max(str[i], first);
                if(str[i] == '0' && first == '0')
                    continue;
                if(count++ > 10)
                    break;
                ans *= 10;
                ans += str[i] - '0';
            }
            else if(str[i] == '-' || str[i] == '+'){
                if(first != ' ')
                    break;
                if(i + 1 < size) {
                    if(str[i + 1] > '9' || str[i + 1] < '0')
                        return 0;
                    else 
                        isNeg = str[i] == '-';
                }
                first = max(str[i], first);
            }
            else if(str[i] == ' ') {
                if(first != ' ')
                    break;
                continue;
            }
            else
                break;
        }
        ans = isNeg ? -ans : ans;
        if(ans >= INT_MIN && ans <= INT_MAX)
            return ans;
        else
            return isNeg ? INT_MIN : INT_MAX;
    }
};