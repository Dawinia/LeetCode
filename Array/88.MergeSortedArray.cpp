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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // time: 4ms 84.16%, space: 8.6MB 97.83%
        nums1.erase(nums1.begin() + m, nums1.end());
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }

    void merge_1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // time: 4ms 84.16%, space: 8.8MB 65.22%
        int i = 0, j = 0;
        nums1.erase(nums1.begin() + m, nums1.end());
        while (i < nums1.size() && j < n)
        {
            while (i < nums1.size() && nums1[i] < nums2[j])
                ++i;
            nums1.insert(nums1.begin() + i, nums2[j]);
            ++j;
        }
        nums1.insert(nums1.end(), nums2.begin() + j, nums2.end());
    }
};

int main()
{
    Solution solution;
    vector<int> nums1{4, 0, 0, 0, 0, 0};
    vector<int> nums2{1, 2, 3, 5, 6};
    int m = 1;
    int n = 5;
    solution.merge(nums1, m, nums2, n);
    for (auto i: nums1)
        cout << i << " ";
    return 0;
}

