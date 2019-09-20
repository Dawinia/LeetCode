//
// Created by Dawinia Lo on 2019/9/20.
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
    vector<int> plusOne(vector<int> &digits)
    {
        // time: 4ms 65.48%, space: 8.7MB 72.13%
        int i = digits.size() - 1;
        digits[i] += 1;
        while(i >= 0)
        {
            if(digits[i]   < 10)
                break;
            digits[i] = 0;
            if(i == 0)
                digits.insert(digits.begin(), 1);
            else
                digits[--i] += 1;
        }
        return digits;
    }
};

int main()
{
    Solution solution;
    vector<int> digits{9};
    for (auto i: solution.plusOne(digits))
        cout << i;
    return 0;
}

