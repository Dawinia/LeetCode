//
// Created by Dawinia Lo on 2019/9/6.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
//        一下为第一次解法，花费时间152ms, 内存10.1MB
//        int temp = -99999;
//        while(true)
//        {
//            if(i == nums.size())
//                break;
//            if(temp != nums[i])
//            {
//                temp = nums[i];
//                i++;
//                continue;
//            }
//            temp = nums[i];
//            nums.erase(nums.begin() + i);
//        }

//        一下为第二次解法，花费时间24ms, 内存9.8MB
        int len = nums.size();
        if(len == 0)
            return 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if(nums[j] != nums[j - 1])
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};

int main()
{
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    cout << solution.removeDuplicates(v) << endl;
    for(auto c: v)
        cout << c << endl;
    return 0;
}

