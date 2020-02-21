/*
 * @Description: 
 * @LastEditTime: 2020-02-19 23:50:56
 */
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.05%)
 * Likes:    2970
 * Dislikes: 95
 * Total Accepted:    461.4K
 * Total Submissions: 868.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates?where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates?unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ? [7],
 * ? [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<int> next;
    vector<vector<int> > ans;
    int aim;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), greater<>());
        aim = target;
        int i, n = candidates.size();
        vector<int> one;
        for(i = 0; i < n; ++i)
        {
            int sub = target - candidates[i];
            next.emplace_back(candidates[i]);
            if(sub != 0)
            {
                get_next(candidates, i, sub);
            }
            if(!next.empty())
            {
                ans.emplace_back(next);
                next.clear();
            }
        }
        return ans;
    }
    void get_next(vector<int> &candidates, int i, int target)
    {
        int n = candidates.size();
        for (; i < n; ++i)
        {
            if(candidates[i] > target)
                continue;
            int sub = target - candidates[i];
            next.emplace_back(candidates[i]);
            if(sub < 0)
            {
                next.clear();
                continue;
            }
            if(sub == 0)
            {
                ans.emplace_back(next);
                next.pop_back();
                continue;
            }
            get_next(candidates, i, sub);
        }
        if(accumulate(next.begin(), next.end(), 0) != aim)
            next.pop_back();
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> can = {2,3,6,7};
    int target = 7;
    for (const auto &i : solution.combinationSum(can, target))
    {
        for (auto ii : i)
            cout << ii << " ";
        cout << endl;
    }
}