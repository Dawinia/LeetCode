//
// Created by Dawinia Lo on 2019/9/18.
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
    int fib_1(int N)
    {
        // 递归
        // time: 12ms 26.23%, space: 8.1MB 100%
        if(N == 1 || N == 0)
            return N;
        return fib(N - 1) + fib(N - 2);

    }

    int fib(int N)
    {
        // time: 0ms 100%, space: 8.5MB 25.37%
        if(data[N] != 0)
            return data[N];
        if(N == 1 || N == 0)
        {
            data[N] = N;
            return N;
        }
        data[N] = fib(N - 1) + fib(N - 2);
        return data[N];
    }

    int data[31] = {0};
};

int main()
{
    Solution solution;
    int n = 30;
    cout << solution.fib(n) << endl;
    return 0;
}

