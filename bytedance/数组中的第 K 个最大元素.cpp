class Solution {
public:
    int maxNum;
    int findKthLargest(vector<int>& nums, int k) {
        maxNum = k;
        vector<int> heap(k, -10000007);
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            if(nums[i] > heap[0]) {
                heap[0] = nums[i];
                adjust(heap, 0);
            }
        }
        return heap[0];
    }
    
    void adjust(vector<int>& heap, int start) {
        int left = 2 * start + 1;
        int right = 2 * start + 2;
        if(left >= maxNum)
            return;
        else if(right >= maxNum) {
            if(heap[start] > heap[left])
                swap(heap[start], heap[left]);
        }
        else if(heap[start] > heap[left] || heap[start] > heap[right]) {
            int index = heap[left] > heap[right] ? right : left;
            swap(heap[start], heap[index]);
            adjust(heap, index);
        }
    }
};