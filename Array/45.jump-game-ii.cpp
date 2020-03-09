/*
 * @Description: 
 * @LastEditTime: 2020-02-22 21:36:49
 */
/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.68%)
 * Likes:    1892
 * Dislikes: 112
 * Total Accepted:    223.8K
 * Total Submissions: 754K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int longest = 0, border = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            longest = max(nums[i] + i, longest);
            if(i == border)
            {
                border = longest;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    cout << solution.jump(nums) << endl;
}