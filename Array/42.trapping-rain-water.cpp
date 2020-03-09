/*
 * @Description: 
 * @LastEditTime: 2020-02-21 23:39:58
 */
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (46.75%)
 * Likes:    5610
 * Dislikes: 105
 * Total Accepted:    429.2K
 * Total Submissions: 917.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int r = height.size() - 1;
        int l = 0;
        int l_max = height[l], r_max = height[r];
        int ans = 0;
        while(l <= r)
        {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if(l_max > r_max)
            {
                ans += r_max - height[r];
                --r;
            }
            else
            {
                ans += l_max - height[l];
                ++l;
            }
        }
        return ans;

        return 0;
    }
};
// @lc code=end

