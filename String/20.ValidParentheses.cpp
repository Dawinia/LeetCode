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
    bool isValid(string s)
    {
        cout << s.size() / 2 << endl;
        if(s.size() % 2 != 0)
            return false;
        stack<char> cs;
        int i = 0;
        char pre;
        while (i < s.size())
        {
            pre = getMatchPrefix(s[i]);
            if(pre != ' ')
            {
                if(cs.empty() || cs.top() != pre)
                    return false;
                else
                    cs.pop();
                ++i;
                continue;
            }
            cs.push(s[i]);
            ++i;
        }
        return cs.empty();
    }
    char getMatchPrefix(char r)
    {
        switch (r)
        {
            case ']': return '[';
            case '}': return '{';
            case ')': return '(';
            default: return ' ';
        }
    }
};

int main()
{
    Solution solution;
    string s = "((";
    cout << solution.isValid(s) << endl;
    return 0;
}

