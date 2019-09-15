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
    vector<int> sortArrayByParity_1(vector<int> &A)
    {
        // time: 32ms, space: 9.5MB
        auto bi = A.begin();
        auto ei = A.end() - 1;
        while(bi < ei)
        {
            if(*bi % 2 == 0)
            {
                ++bi;
                continue;
            }
            if(*ei % 2 != 0)
            {
                --ei;
                continue;
            }
            swap(*bi, *ei);
        }
        return A;
    }

    vector<int> sortArrayByParity(vector<int> &A)
    {
        // time: 20ms, space: 9.7MB
        auto bi = A.begin();
        auto ei = A.end() - 1;
        while(bi < ei)
        {
            while(bi < ei && *bi % 2 == 0)
                ++bi;
            while(bi < ei && *ei % 2 != 0)
                --ei;
            swap(*bi, *ei);
            ++bi;
            --ei;
        }
        return A;
    }
};

int main()
{
    Solution solution;
    vector<int> a{3,1,2,4};
    solution.sortArrayByParity(a);
    for (int re : a)
    {
        cout << re << " ";
    }
    return 0;
}

