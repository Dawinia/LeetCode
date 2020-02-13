//
// Created by Dawinia Lo on 2020/1/10.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans = {1};
        vector<int> prev = {1};
        for (int i = 1; i <= rowIndex; ++i)
        {
            ans.push_back(1);
            for (int j = 1; j <= i; ++j)
            {
                ans.clear();
                ans.push_back(prev[j - 1] + prev[j]);
            }
            ans.push_back(1);
            prev.assign(ans.begin(), ans.end());
        }
        return ans;
    }

    double comb_log(int m, int n)
    {
        int i;
        if (n > m - n)
            n = m - n;
        if (n == 1)
            return m;
        if (n == 0)
            return 1;
        double s1 = 0.0, s2 = 0.0;
        for (i = m - n + 1; i <= m; ++i)
            s1 += log(i);
        for (i = 1; i <= n; ++i)
            s2 += log(i);
        return exp(s1 - s2);
    }

    int comb(int m, int n)
    {
        if (n == 1)
            return m;
        if (n == 0)
            return 1;
        if (n > m / 2)
            return comb(m, m - n);
        if (n > 1)
            return (comb(m - 1, n - 1) + comb(m - 1, n));
        return 0;
    }

};

int main()
{
    Solution solution;
    for (auto i: solution.getRow(3))
        cout << i << " ";
//    cout << endl << solution.comb_log(33, 15);
    return 0;
}

