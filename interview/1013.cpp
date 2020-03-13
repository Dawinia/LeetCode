//
// Created by Dawinia Lo on 2020/3/11.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        sum = accumulate(A.begin(), A.end(), 0);
        if(sum % 3 != 0)
            return false;
        int i = 0, gap = sum / 3, size = A.size(), s = 0, count = 0;
        while(i < size) {
            s += A[i++];
            if(count == 2) {
                return accumulate(A.begin() + i, A.end(), 0) + s == gap;
            }
            if(s == gap) {
                ++count;
                s = 0;
            }
        }
        return count == 3;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {0,2,1,-6,6,-7,9,1,2,0,1};
    cout << solution.canThreePartsEqualSum(a) << endl;
    return 0;
}

