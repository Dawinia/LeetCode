//
// Created by Dawinia Lo on 2019/9/18.
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
    int searchInsert(vector<int> &nums, int target)
    {
        // time: 4ms 98.45%, space: 8.7MB 100%
        int h = 0, t = nums.size() - 1;
        if(t == 0)
            return target > nums[0] ? 1 : 0;
        int mid = (h + t) / 2;
        while (target != nums[mid] && t - h > 1)
        {
            target > nums[mid] ? h = mid : t = mid;
            mid = (h + t) / 2;
        }
        if(target == nums[mid])
            return mid;
        else if(target > nums[t])
            return t + 1;
        return target > nums[mid] ? h + 1 : t - 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 3, 5, 9};
    int target = 2;
    cout << solution.searchInsert(nums, target) << endl;
    return 0;
}

