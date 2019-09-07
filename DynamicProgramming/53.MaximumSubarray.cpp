//
// Created by Dawinia Lo on 2019/9/7.
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
    int maxSubArray(vector<int> &nums)
    {
//        以下为第一次解法，T = 8ms, M = 9.1MB
//        if(nums.size() == 1)
//            return nums[0];
//        int m = 0;
//        int n = 0;
//        for (int num : nums)
//        {
//            m = max(num, m + num);
//            n = max(m, n);
//        }
//        return n;

//        以下为第二次解法，T = 4ms, M = 9.3MB
        if(nums.size() == 1)
            return nums[0];
        int m = -99999;
        int n = -99999;
        for (int num : nums)
        {
            m = num > (m + num) ? num : (m + num);
            n = m > n ? m : n;
        }
        return n;
    }
};

int main()
{
    Solution solution;
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(v) << endl;
    return 0;
}

