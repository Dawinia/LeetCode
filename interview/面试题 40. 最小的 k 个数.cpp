class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int size = arr.size();
        if(k == size)
            return arr;
        vector<int> ans(k, 0);
        if(k == 0)
            return ans;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; ++i)
            ans[i] = arr[i];
        return ans;
    }
};