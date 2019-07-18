//
// Created by Dawinia Lo on 2019/7/17.
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
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int minTarget = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                minTarget = abs(minTarget - target) > abs(sum - target) ? sum : minTarget;
                if (sum == target)
                    return target;
                else if (sum > target)
                    --r;
                else
                    ++l;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }
        return minTarget;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0, 2, 1, -3};
    int target = 1;
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}

