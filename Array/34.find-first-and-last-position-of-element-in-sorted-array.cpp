/*
 * @Description: 
 * @LastEditTime: 2020-02-19 18:46:30
 */
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (35.01%)
 * Likes:    2537
 * Dislikes: 116
 * Total Accepted:    416K
 * Total Submissions: 1.2M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return {-1, -1};
        int l = 0, h = n;
        int mid;
        vector<int> ans;
        while(l < h)
        {
            mid = l + (h - l) / 2;
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        if(l == n || nums[l] != target)
            return {-1, -1};
        ans.emplace_back(l);
        h = n;
        while(l < h)
        {
            mid = l + (h - l) / 2;
            if(nums[mid] > target)
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans.emplace_back(h - 1);
        return ans;
    }
};

// @lc code=end