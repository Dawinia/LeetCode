/*
 * @Description: 
 * @LastEditTime: 2020-02-21 12:36:21
 */
/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.73%)
 * Likes:    2610
 * Dislikes: 712
 * Total Accepted:    284K
 * Total Submissions: 923.9K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int j = 0; j < n; ++j)
        {
            while(nums[j] != j + 1)
                return j + 1;
        }
        return n + 1;
    }
};
// @lc code=end
int main()
{
    Solution solution;
    vector<int> nums = {5,8,3,12,4,7,2,1,6,9,11};
    cout << solution.firstMissingPositive(nums) << endl;
}