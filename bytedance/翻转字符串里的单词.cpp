class Solution {
public:
    string reverseWords(string s) {
        stack<string> ss;
        s += " ";
        int size = s.length();
        if(size == 1)
            return "";
        string ans = "";
        string word = "";
        for(int i = 0; i < size; ++i) {
            if(s[i] == ' ' && !word.empty()) {
                ss.push(word);
                word = "";
                ss.push(" ");
                continue;
            }
            if(s[i] != ' ')
                word += s[i];
        }
        while(!ss.empty()) {
            ans += ss.top();
            ss.pop();
        }
        return ans.length() ? ans.substr(1) : ans;
    }
};