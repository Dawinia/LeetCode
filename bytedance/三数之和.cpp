class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int> > ans;
        if(size == 0)
            return {};
        if(size == 1 && nums[0] != 0)
            return {};
        sort(nums.begin(), nums.end());
        if(nums[0] <= 0 && nums[size - 1] >= 0) {
            for(int i = 0; i < size - 2; ++i) {
                if(i > 0 && nums[i] == nums[i - 1])
                    continue;
                if(nums[i] > 0)
                    break;
                int sub = 0 - nums[i];
                int l = i + 1;
                int r = size - 1;
                do {
                    if(l >= r)
                        break;
                    if(nums[l] + nums[r] == sub)
                        ans.push_back({nums[i], nums[l], nums[r]});
                    if(nums[l] + nums[r] > sub)
                        while (l < r && nums[r] == nums[--r]){}
                    else
                        while (l < r && nums[l] == nums[++l]){}
                }while(l < r);
            }
        }
        return ans;

    }
};