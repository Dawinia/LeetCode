//
// Created by Dawinia Lo on 2019/9/20.
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
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // time: 8ms 42.43%, 8.6MB 100%
        int i = 0;
        int j = 0;
        int temp;
        while (j < arr2.size())
        {
            for (int k = 0; k < arr1.size(); ++k)
            {
                if (arr1[k] == arr2[j])
                {
                    temp = arr1[k];
                    arr1[k] = arr1[i];
                    arr1[i] = temp;
                    ++i;
                }
            }
            ++j;
        }
        partial_sort(arr1.begin() + i, arr1.end(), arr1.begin() + i);
        return arr1;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2{2, 1, 4, 3, 9, 6};
    for (auto i: solution.relativeSortArray(arr1, arr2))
    {
        cout << i << " ";
    }
    return 0;
}

