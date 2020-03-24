class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())
            return NULL;
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        int size1 = num1.length();
        int size2 = num2.length();
        string ans(size1 + size2, '0');
        for(int i = size1 - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            for(int j = size2 - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int s = n1 * n2 + (ans[i + j + 1] - '0');
                int c = ans[i + j] - '0';
                ans[i + j] = (c + s / 10) + '0';
                ans[i + j + 1] = s % 10 + '0';
            }
        }
        if(ans[0] == '0')
            return ans.substr(1);
        return ans;
    }
};