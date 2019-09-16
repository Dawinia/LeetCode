//
// Created by Dawinia Lo on 2019/9/16.
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
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        // time: 72ms 9.9%, space: 11.9MB 56.25%
        int i = 0, j = 1;
        int size = A.size();
        while (i < size || j < size)
        {
            while (i < size && A[i] % 2 == 0)
                i += 2;
            while (j < size && A[j] % 2 != 0)
                j += 2;
            if(i < size && j < size)
                A[i] ^= A[j] ^= A[i] ^= A[j];
        }
        return A;
    }
};

int main()
{
    Solution solution;
    vector<int> a{4, 2, 5, 7};
    solution.sortArrayByParityII(a);
    for (auto i: a)
        cout << i << endl;
    return 0;
}

