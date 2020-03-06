/*
 * @Description: 
 * @LastEditTime: 2020-02-23 16:05:00
 */
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (53.30%)
 * Likes:    2375
 * Dislikes: 198
 * Total Accepted:    344K
 * Total Submissions: 644.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size() - 1;
        rotateBorder(matrix, 0, n, n);
    }

    void rotateBorder(vector<vector<int>> &matrix, int l, int r, int n)
    {
        if (l >= r)
            return;
        for (int i = l; i < r; ++i)
        {
            swap(matrix[l][i], matrix[i][n - l]);
            swap(matrix[l][i], matrix[n - l][n - i]);
            swap(matrix[l][i], matrix[n - i][l]);
        }
        rotateBorder(matrix, l + 1, r - 1, n);
    }
};
// @lc code=end
int main()
{
    Solution solution;
    vector<vector<int> > matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    solution.rotate(matrix);
    for (const auto &i: matrix)
    {
        for (auto ii: i)
            cout << ii << " ";
        cout << endl;
    }
}
