/*
 * @Description: 
 * @LastEditTime: 2020-02-23 18:09:19
 */
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.67%)
 * Likes:    1781
 * Dislikes: 495
 * Total Accepted:    315.2K
 * Total Submissions: 964K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m <= 0)
            return {};
        int n = matrix[0].size();
        int rBegin = 0, cBegin = 0;
        int rEnd = m - 1, cEnd = n - 1;
        vector<int> ans;
        while (ans.size() < n * m)
        {
            for (int j = rBegin; j <= cEnd && ans.size() < n * m; ++j)
            {
                ans.emplace_back(matrix[cBegin][j]);
            }
            for (int i = rBegin + 1; i <= rEnd && ans.size() < n * m; ++i)
            {
                ans.emplace_back(matrix[i][cEnd]);
            }
            for (int j = cEnd - 1; j >= rBegin && ans.size() < n * m; --j)
            {
                ans.emplace_back(matrix[rEnd][j]);
            }
            for (int i = rEnd - 1; i >= cBegin + 1 && ans.size() < n * m; --i)
            {
                ans.emplace_back(matrix[i][cBegin]);
            }
            ++cBegin, ++rBegin, --cEnd, --rEnd;
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution solution;
    vector<vector<int> > nums = {
    };
    for(auto i: solution.spiralOrder(nums))
    {
        cout << i << " ";
    }
}
