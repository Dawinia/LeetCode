//
// Created by Dawinia Lo on 2019/9/16.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
  public:
    int heightChecker(vector<int> &heights)
    {
        // time: 4ms 63.52%, space: 8.4MB 100%
        vector<int> temp(heights);
        sort(heights.begin(), heights.end());
        transform(heights.begin(), heights.end(), temp.begin(), temp.begin(), [](int a, int b)
        { return a - b == 0 ? 0 : 1; });
        return accumulate(temp.begin(), temp.end(), 0);
    }
};

int main()
{
    Solution solution;
    vector<int> a{1, 1, 4, 2, 1, 3};
    cout << solution.heightChecker(a) << endl;
    return 0;
}

