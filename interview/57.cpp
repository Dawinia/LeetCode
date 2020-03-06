//
// Created by Dawinia Lo on 2020/3/6.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    vector<int> one;
    int begin = 1;
    int sum = 0;
    int i = 1;
public:
    vector<vector<int>> findContinuousSequence(int target) {
        while(i < target) {
            sum += i;
            if(sum == target) {
                dosome();
                continue;
            }
            while(sum > target) {
                sum -= begin;
                ++begin;
                if(sum == target) {
                    dosome();
                    --i;
                    break;
                }
            }
            ++i;
        }
        return ans;
    }

    void dosome() {
        insert();
        ++begin;
        i = begin;
        sum = 0;
        ans.emplace_back(one);
        one.clear();
    }

    void insert() {
        for(int j = begin; j <= i; ++j) {
            one.emplace_back(j);
        }
    }
};

int main()
{
    Solution solution;
    for(auto i: solution.findContinuousSequence(15)) {
        for(auto ii: i) {
            cout << ii << " ";
        }
        cout << endl;
    }
    return 0;
}

