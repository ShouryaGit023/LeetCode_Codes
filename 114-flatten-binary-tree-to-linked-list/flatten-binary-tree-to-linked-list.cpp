class Solution {
private:
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Traverse right then left (reverse preorder)
        flatten(root->right);
        flatten(root->left);

        // Re-link nodes
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};