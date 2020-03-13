class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        return nums[0] == nums[size / 2] ? nums[0] : nums[size / 2];
    }
};