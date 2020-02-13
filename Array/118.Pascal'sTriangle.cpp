//
// Created by Dawinia Lo on 2020/1/10.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        // time: 0ms 100%, space: 8.8MB 74.07%
        vector<vector<int> > ans;
        vector<int> row;
        for(int i = 0; i < numRows; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                if(j == 0 || i == j)
                    row.push_back(1);
                else
                {
                    row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int i = 5;
    for(const auto& ans: solution.generate(i))
    {
        for(auto j: ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

