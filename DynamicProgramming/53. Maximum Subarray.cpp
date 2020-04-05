class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if(nums.size() == 1)
            return nums[0];
        int m = -99999;
        int n = -99999;
        for (int num : nums)
        {
            m = num > (m + num) ? num : (m + num);
            n = m > n ? m : n;
        }
        return n;
    }
};