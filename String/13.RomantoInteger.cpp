//
// Created by Dawinia Lo on 2019/9/7.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int sum = 0, i = 0;
        while (i < s.size())
        {
            while (singleRomanToInt(s[i]) < singleRomanToInt(s[i + 1]))
            {
                sum -= singleRomanToInt(s[i]);
                ++i;
            }
            sum += singleRomanToInt(s[i]);
            ++i;
        }
        return sum;
    }
    int singleRomanToInt(char roman)
    {
        switch (roman)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main()
{
    Solution solution;
    string s = "MCMXCIV";
    cout << solution.romanToInt(s) << endl;
    return 0;
}

