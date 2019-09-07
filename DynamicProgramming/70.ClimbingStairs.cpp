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
    int climbStairs(int n)
    {
//        int * a = new int[n + 1];
//        a[0] = a[1] = 1;
//        for (int i = 2; i < n + 1; ++i)
//        {
//            a[i] = a[i - 1] + a[i - 2];
//        }
//        return a[n];

        if ((n == 0) || (n == 1))
            return 1;
        int a = 1, b = 1;    //a: # of 1 step before, b: # of 2 steps before
        int res = 0;
        for (int i = 2; i <= n; ++i)
        {
            res = a + b;
            b = a;
            a = res;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n = 5;
    cout << solution.climbStairs(n) << endl;
    return 0;
}

