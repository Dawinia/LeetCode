//
// Created by Dawinia Lo on 2019/9/7.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty())
            return "";
        sort(strs.begin(), strs.end(), cmp);
        for (int i = 0; i < strs[0].size(); ++i)
        {
            for (int j = 0; j < strs.size() - 1; ++j)
            {
                if(strs[j][i] != strs[j + 1][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
    bool static cmp(string &a, string &b)
    {
        return a.size() < b.size();
    }
};
int main()
{
    Solution solution;
    vector<string> str{"dog","racecar","car"};
    cout << solution.longestCommonPrefix(str) << endl;
    return 0;
}

