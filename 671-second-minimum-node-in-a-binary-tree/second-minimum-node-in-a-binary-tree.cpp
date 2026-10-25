class Solution {
public:
    long long s = -1; // Use long long to handle edge cases with INT_MAX

    void dfs(TreeNode* root, int f) {
        if (!root) return;
        
        // If we find a value strictly greater than the minimum (f)
        if (root->val > f) {
            if (s == -1 || root->val < s) {
                s = root->val;
            }
            return; // No need to go deeper in this branch since all children will be >= root->val
        }
        
        // If root->val == f, search both children
        dfs(root->left, f);
        dfs(root->right, f);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        dfs(root, root->val);
        return s;
    }
};