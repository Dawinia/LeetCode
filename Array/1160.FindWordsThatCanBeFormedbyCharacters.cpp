//
// Created by Dawinia Lo on 2019/9/16.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{
  public:
    int countCharacters(vector<string> &words, string chars)
    {
        // time: 76ms 69.86%, space: 15.1MB 100%
        int count = 0;
        string temp = chars;
        bool flag = false;
        for (auto &word : words)
        {
            for (auto c: word)
            {
                int pos = chars.find(c);
                if (pos == std::__cxx11::string::npos)
                {
                    flag = true;
                    break;
                }
                else
                    chars.erase(pos, 1);
            }
            if (!flag)
                count += word.length();
            flag = false;
            chars = temp;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<string> words{"hello", "world", "leetcode"};
    string chars = "atach";
    cout << solution.countCharacters(words, chars) << endl;
    return 0;
}

