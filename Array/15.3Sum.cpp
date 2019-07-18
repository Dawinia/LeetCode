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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int target = -nums[i];
            if (target < 0)
                break;
            int l = i + 1;
            int r = nums.size() - 1;
            if (nums[i] + nums[l] > 0)
                break;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (target == sum)
                {
                    vector<int> oneRes = {nums[i], nums[l], nums[r]};
                    result.push_back(oneRes);
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                } else if (target < sum)
                {
                    r--;
                } else
                {
                    l++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, -1, -1, 0};
    for (int i = 0; i < solution.threeSum(nums).size(); ++i)
    {
        for (int j = 0; j < solution.threeSum(nums)[i].size(); ++j)
        {
            cout << solution.threeSum(nums)[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

