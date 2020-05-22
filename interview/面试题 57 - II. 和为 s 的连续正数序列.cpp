class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 1;
        int sum = 0;
        vector<vector<int> > ans;
        while (i <= target / 2) {
            if (sum < target) {
                sum += j;
                ++j;
            }
            else if (sum > target) {
                sum -= i;
                ++i;
            }
            else {
                vector<int> row;
                for(int k = i; k < j; ++k)
                    row.push_back(k);
                ans.push_back(row);
                sum -= i;
                ++i;
            }
        }
        return ans;
    }
        
};