class Tree {
    vector<int> treeList;
    int length;

public:
    Tree(int len) {
        treeList.resize(len + 1);
        length = len;
    }

    void update(int i, int delta) {
        while(i <= length) {
            treeList[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += treeList[i];
            i -= lowbit(i);
        }
        return sum;
    }

    int lowbit(int i) {
        return i & (-i);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return {};
        }
        if(size == 1)
            return {0};
        Tree tree(size);
        map<int, int> rank;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        for(int i = 0; i < size; ++i) {
            rank[temp[i]] = i + 1;
        }
        vector<int> ans(size, 0);
        for(int i = size - 1; i >= 0; --i) {
            int r = rank[nums[i]];
            tree.update(r, 1);
            ans[i] = tree.query(r - 1);
        }
        return ans;
    }
};