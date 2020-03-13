class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int size = light.size();
        int m = light[0];
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            m = max(m, light[i]);
            if(m == i + 1)
                ++ans;
        }
        return ans;
    }
};