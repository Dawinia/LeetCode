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
        for(auto i: A) {
            sum += i;
        }
        if(sum % 3 != 0)
            return false;
        int i = 0, gap = sum / 3, size = A.size(), s = 0, count = 0;
        while(i < size) {
            if(s == gap) {
                ++count;
                s = 0;
            }
            s += A[i++];
        }
        return count == 2;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {12,-4,16,-5,9,-3,3,8,0};
    cout << solution.canThreePartsEqualSum(a) << endl;
    return 0;

}

