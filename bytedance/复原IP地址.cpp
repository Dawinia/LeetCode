class Solution {
public:
    vector<string> ans;
    int size;
    vector<string> restoreIpAddresses(string s) {
        size = s.length();
        if(size < 4 || size > 12)
            return {};
        string path = "";
        dfs(s, 0, 0, path);
        return ans;
    }

    void dfs(string s, int start, int depth, string path) {
        if(depth == 4) {
            path.pop_back();
            ans.emplace_back(path);
            return;
        }
        int maxN = (3 - depth) * 3;
        int minN = (3 - depth) * 1;
        for(int i = 1; i <= 3; ++i) {
            int rest = size - i - start;
            if(rest > maxN || rest < minN)
                continue;
            string sub = s.substr(start, i);
            if(sub.size() > 1 && sub[0] == '0')
                continue;
            if(stoi(sub) <= 255)
                dfs(s, start + i, depth + 1, (path + sub + '.'));
        }
    }
};