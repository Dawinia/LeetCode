class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int size = A.size();
        if(size <= 1)
            return 0;
        int ans = 0;
        sort(A.begin(), A.end());
        for(int i = 1; i < size; ++i) {
            if(A[i] <= A[i - 1]) {
                ans += A[i - 1] + 1 - A[i];
                A[i] = A[i - 1] + 1;
            }
        }
        return ans;
    }
};