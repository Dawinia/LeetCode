class Solution {
private:
    int minSize = 0;
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string ans = "";
        if(strs.size() == 0)
            return ans;
        if(strs.size() == 1)
            return strs[0];
        minSize = strs[0].size();
        if(minSize == 0)
            return ans;
        while(1) {
            if(!same(strs, i))
                return ans;
            ans += strs[0][i];
            ++i;
        }
        return ans;
    }
    
    bool same(vector<string>& strs, int i) {
        int size = strs.size();
        for(int j = 1; j < size; ++j) {
            if(strs[j][i] == '\0')
                return false;
            if(strs[j][i] != strs[j - 1][i])
                return false;
        }
        return true;
    }
};