//
// Created by Dawinia Lo on 2019/7/30.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<vector<int>> res;
        if (nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        vector<int> tt = nums;
        int temp;
        int prev = -99999999;
        for (int i = 0; i < tt.size() - 3; ++i)
        {
            nums.erase(nums.begin());
            if(prev == tt[i])
                continue;
            temp = target - tt[i];
            prev = tt[i];
            res = threeSum(nums, temp);
            for (int j = 0; j < res.size(); ++j)
            {
                res[j].insert(res[j].begin(), tt[i]);
                ans.push_back(res[j]);
            }
            res.clear();
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
    vector<vector<int>> threeSum(vector<int> &nums, int aim)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int target = aim - nums[i];
            if (target < nums[i + 1] && nums[i + 1] > 0)
                break;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (target == sum)
                {
                    vector<int> oneRes = {nums[i], nums[l], nums[r]};
                    result.push_back(oneRes);
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                } else if (target < sum)
                {
                    r--;
                } else
                {
                    l++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {2, 0, 3, 0, 1, 2, 4};
    int target = 7;
    vector<vector<int>> ans = solution.fourSum(v, target);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

