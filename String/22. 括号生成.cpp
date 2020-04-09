class Solution {
public:

    vector<string> generateParenthesis(int n) {
        if(n < 1)
            return {};
        if(n == 1)
            return {"()"};
        vector<string> ans;
        dfs("", 0, 0, n, ans);

        return ans;
    }

    void dfs(string cur, int left, int right, int n, vector<string>& ans) {
        if(left == n && right == n) {
            ans.push_back(cur);
            return;
        }
        if(left < right)
            return;
        if(left < n) {
            dfs(cur + "(", left + 1, right, n, ans);
        }
        if(right < n) {
            dfs(cur + ")", left, right + 1, n, ans);
        }
    }
};