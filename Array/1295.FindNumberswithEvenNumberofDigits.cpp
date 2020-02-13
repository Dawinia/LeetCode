//
// Created by Dawinia Lo on 2020/1/10.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
  public:
    int findNumbers(vector<int> &nums)
    {
        // time: 4ms 98.34%, space: 9.2MB 100%
        int count = 0;
        for (int num : nums)
        {
            if ((1 + int(log10(num))) % 2 == 0)
                ++count;
        }
        return count;
    }
    int getDigitNumbet(int num)
    {
        int count = 0;
        while(num != 0)
        {
            num /= 10;
            ++count;
        }
        return count;
    }

    int findNumbers_1(vector<int> &nums)
    {
        int count = 0;
        for(auto num: nums)
        {
            if(getDigitNumbet(num) % 2 == 0)
                ++count;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << solution.findNumbers_1(nums) << endl;
    return 0;
}

