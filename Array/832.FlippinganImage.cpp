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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for(auto & i : A)
        {
            auto bi = i.begin();
            auto ei = i.end() - 1;
            int temp = 0;
            while(bi < ei)
            {
                swap(*bi, *ei);
                *bi = !*bi;
                *ei = !*ei;
                ++bi;
                --ei;
            }
            if(bi == ei)
                *bi = !*bi;
        }
        return A;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> a{{1,1,0},{1,0,1},{0,0,0}};
    solution.flipAndInvertImage(a);
    for (auto & i : a)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

