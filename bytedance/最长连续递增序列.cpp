class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return size;
        int ans = 0;
        int temp = 1;
        for(int i = 1; i < size; ++i) {
            if(nums[i] > nums[i - 1])
                ++temp;
            else {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};