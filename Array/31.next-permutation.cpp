/*
 * @Description: 
 * @LastEditTime : 2020-02-13 18:39:49
 */
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size() - 1, i = -1, j = 0;
        for (i = size - 1; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            for (j = size; j > i; --j)
            {
                if (nums[j] > nums[i])
                    break;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
// @lc code=end

