//
// Created by Dawinia Lo on 2019/9/6.
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
    int removeElement(vector<int> &nums, int val)
    {
//        if(nums.size() == 1 && nums[0] == val)
//            return 0;
//        int h = 0;
//        int l = nums.size() - 1;
//        while (h <= l)
//        {
//            if(nums[h] == val)
//            {
//                while (l > h && nums[l] == val)
//                    --l;
//                nums[h] = nums[l];
//                --l;
//            }
//            if(h <= l && nums[h] != val)
//                ++h;
//        }
//        return h;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {3, 3};
    cout << solution.removeElement(a, 3) << endl;
    return 0;
}

