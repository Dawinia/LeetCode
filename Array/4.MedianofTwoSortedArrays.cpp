//
// Created by Dawinia Lo on 2019/4/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double half = (nums1.size() + nums2.size()) / 2.0;
        if(nums1[nums1.size() - 1] < nums2[0])
        {
//            int index = half > nums1.size() ? ceil(half) - nums1.size() : ceil(half) - 1;
        }
        return half;
    }
};

int main()
{
    vector<int> a = {1, 2, 4, 6, 8, 9};
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    cout << a[a.size() - 1] << endl;
    a.insert(a.begin() + 3, 5);
    cout << a.size() << endl;
    for(auto i : a)
        cout << i << " ";
    return 0;
}
