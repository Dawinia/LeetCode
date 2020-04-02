class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int>& nums, int left, int right) {
        if(left >= right)
            return;
        int pivot = nums[left];
        int l = left, r = right;
        while(l < r) {
            while(l < r && nums[r] >= pivot)
                r--;
            while(l < r && nums[l] <= pivot)
                l++;
            if(l < r)
                swap(nums[l], nums[r]);
        }
        nums[left] = nums[l];
        nums[l] = pivot;
        qsort(nums, left, l - 1);
        qsort(nums, l + 1, right);
    }
};