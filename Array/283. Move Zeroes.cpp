class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, size = nums.size(), right = 1;
        if(size < 2)
            return;
        while(left < size - 1 || right < size) {
            while(left < size - 1 && nums[left] != 0)
                ++left;
            right = max(right, left + 1);
            while(right < size && nums[right] == 0)
                ++right;
            if(right >= size)
                return;
            swap(nums[left], nums[right]);
            ++left;
            ++right;
        }
    }
};