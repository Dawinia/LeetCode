class Solution {
public:
    string simplifyPath(string path) {
        stack<char> ps;
        int size = path.length();

        ps.push(' ');
        int i = 0;
        string ans = "";
        while(i < size) {
            if(path[i] == '/' && ps.top() == '/') {
                ++i;
                continue;
            }
            if(path[i] == '.') {
                int count = 1;
                int j = i + 1;
                for(; j < size; ++j) {
                    if(path[j] == '/')
                        break;
                    ++count;
                }
                if(count == 1) {
                    ++i;
                    continue;
                }
                else if(count == 2) {
                    if(ps.size() > 2)
                        ps.pop();
                    while(!ps.empty() && ps.top() != '/')
                        ps.pop();
                    if(ps.size() > 2)
                        ps.pop();
                    i += 2;
                    continue;
                } else {
                    for(;i < j; ++i) {
                        ps.push(path[i]);
                    }
                    continue;
                }
            }
            ps.push(path[i]);
            ++i;
        }
        while(!ps.empty()) {
            ans += ps.top();
            ps.pop();
        }
        reverse(ans.begin(), ans.end());
        ans = ans.substr(1);
        int as = ans.size();
        if(as > 1 && ans[as - 1] == '/')
            ans = ans.substr(0, as - 1);
        return ans;
    }
};