//
// Created by Dawinia Lo on 2019/4/20.
//

//
// Created by Dawinia Lo on 2019/4/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        int index;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if(find(iter + 1, nums.end(), target - (*iter)) != nums.end())
            {
                index = getIndex(nums, (*iter), 0);
                result.push_back(index);
                result.push_back(getIndex(nums, target - (*iter), index + 1));
                return result;
            }
        }
        return result;
    }

    int getIndex(vector<int> &nums, int target, int position)
    {
        for (int i = position; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {3, 2, 4};
    for (auto i: solution.twoSum(a, 6))
        cout << i << endl;
    return 0;
}