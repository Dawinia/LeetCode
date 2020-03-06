/*
 * @Description: 
 * @LastEditTime: 2020-02-23 19:21:44
 */
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.91%)
 * Likes:    3252
 * Dislikes: 249
 * Total Accepted:    499.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size() - 1;
        if(n < 0)
            return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > ans;
        vector<int> mid;
        mid = intervals[0];
        for (int i = 1; i <= n; ++i)
        {
            if (mid[1] < intervals[i][0])
            {
                ans.emplace_back(mid);
                mid = intervals[i];
                continue;
            } else
            {
                if (mid[1] < intervals[i][1])
                {
                    mid[1] = intervals[i][1];
                }
            }
        }
        ans.emplace_back(mid);
        return ans;
    }

    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

};
// @lc code=end
