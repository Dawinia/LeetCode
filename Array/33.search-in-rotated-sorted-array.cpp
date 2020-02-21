/*
 * @Description: 
 * @LastEditTime : 2020-02-14 19:15:53
 */
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    3686
 * Dislikes: 402
 * Total Accepted:    569K
 * Total Submissions: 1.7M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * min_index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        int h = size - 1;
        int l = 0, mid = h / 2;
        int ll;
        while (l < h)
        {
            if (nums[l] < nums[h])
            {
                ll = l;
                break;
            }
            else
            {
                if (nums[mid] > nums[h])
                    l = mid + 1;
                else
                    h = mid;
            }
            mid = (l + h) / 2;
        }
        ll = l;
        l = 0;
        h = size - 1;
        while (l <= h)
        {
            mid = (l + h) / 2;
            int rmid = (mid + ll) % size;
            if (target == nums[rmid])
                return rmid;
            else if (target < nums[rmid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
// @lc code=end