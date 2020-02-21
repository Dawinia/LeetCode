/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (45.50%)
 * Likes:    1327
 * Dislikes: 55
 * Total Accepted:    285K
 * Total Submissions: 626.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> next;
    map<int, int> elemCnt;
    vector<int> uniqueCand;
    int aim;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        aim = target;
        if (candidates.size() == 1 && candidates[0] != target)
            return ans;
        get_unique(candidates);
        sort(uniqueCand.begin(), uniqueCand.end(), greater<>());
        int n = uniqueCand.size();
        for (int i = 0; i < n; ++i)
        {
            if (uniqueCand[i] > target)
                continue;
            int sub = target - uniqueCand[i];
            next.emplace_back(uniqueCand[i]);
            elemCnt[uniqueCand[i]]--;
            if (sub != 0)
                get_next(uniqueCand, i, sub);
            if (!next.empty())
            {
                ans.emplace_back(next);
                next.clear();
            }
        }
        return ans;
    }
    void get_unique(vector<int> &candidates)
    {
        for (auto i : candidates)
        {
            if (count(uniqueCand.begin(), uniqueCand.end(), i) > 0)
            {
                elemCnt[i]++;
                continue;
            }
            elemCnt[i] = 1;
            uniqueCand.emplace_back(i);
        }
    }

    void get_next(vector<int> &candidates, int i, int target)
    {
        int n = candidates.size();
        for (; i < n; ++i)
        {
            if (candidates[i] > target)
                continue;
            if (elemCnt[candidates[i]] == 0)
                continue;
            elemCnt[candidates[i]]--;
            int sub = target - candidates[i];
            next.emplace_back(candidates[i]);
            if (sub < 0)
            {
                next.clear();
                continue;
            }
            if (sub == 0)
            {
                ans.emplace_back(next);
                int element = next.back();
                next.pop_back();
                elemCnt[element]++;
                continue;
            }
            get_next(candidates, i, sub);
        }
        if (accumulate(next.begin(), next.end(), 0) != aim)
        {
            int element = next.back();
            next.pop_back();
            elemCnt[element]++;
        }
    }
};
// @lc code=end
int main()
{
    Solution solution;
    vector<int> can = {1, 2};
    int target = 2;
    for (const auto &i : solution.combinationSum2(can, target))
    {
        for (auto ii : i)
            cout << ii << " ";
        cout << endl;
    }
}
