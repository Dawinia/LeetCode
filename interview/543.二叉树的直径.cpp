class Solution {
private:
    int max_sum = 1;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        get_max(root);
        return max_sum - 1;
    }

    int get_max(TreeNode* root) {
        if(root == NULL) 
            return 0;
        int left = get_max(root->left);
        int right = get_max(root->right);
        max_sum = max(max_sum, left + right + 1);
        return max(left, right) + 1;
    }
};