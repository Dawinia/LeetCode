//
// Created by Dawinia Lo on 2019/7/17.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int maxArea(vector<int> &height)
{
    int max_area = 0;
    int l = 0;
    int r = height.size() - 1;
    int shortLine = 0;
    while(l < r)
    {
        shortLine = min(height[l], height[r]);
        max_area = max(max_area, (r - l) * shortLine);
        if(height[l] == shortLine)
            l++;
        else
            r--;
    }
    return max_area;
}

int main()
{
    vector<int> lines = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(lines) << endl;
    return 0;
}

