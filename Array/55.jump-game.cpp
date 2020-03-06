/*
 * @Description: 
 * @LastEditTime: 2020-02-23 18:16:18
 */
/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (33.16%)
 * Likes:    3032
 * Dislikes: 270
 * Total Accepted:    362K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n < 0)
            return false;
        int mid = n;
        for (int i = n; i >= 0; --i)
        {
            if(nums[i] + i >= n || nums[i] + i >= mid)
            {
                mid = i;
            }
        }
        return mid == 0;
        
    }
};
// @lc code=end

