//
// Created by Dawinia Lo on 2019/9/15.
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
    int arrayPairSum(vector<int> &nums)
    {
        //time: 76ms 67.63%, space: 11.2MB 100%
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> a{1,4,3,2};
    cout << solution.arrayPairSum(a) << endl;
    return 0;
}

