//
// Created by Dawinia Lo on 2019/9/15.
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
    vector<int> sortedSquares(vector<int> &A)
    {
        //time: 116ms 50.43%, space: 13.4MB 93.24%
        for(auto &a: A)
            a *=a;
        sort(A.begin(), A.end());
        return A;
    }
};

int main()
{
    Solution solution;
    vector<int> a{-7, -3, 2, 3, 11};
    solution.sortedSquares(a);
    for (auto i: a)
    {
        cout << i << endl;
    }
    return 0;
}

