class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return size;
        sort(nums.begin(), nums.end());
        int temp = nums[0];
        int m = 1;
        int ans = 0;
        for(int i = 1; i < size; ++i) {
            if(nums[i] == temp + 1) {
                ++m;
            }
            else if(nums[i] == temp) {
                continue;
            }
            else {
                ans = max(ans, m);
                m = 1;
            }
            temp = nums[i];
        }
        ans = max(ans, m);
        return ans;
    }

};