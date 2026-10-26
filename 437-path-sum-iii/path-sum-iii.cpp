/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    map<long long ,int> m;
    long long p=0;
    void dfs(TreeNode* root,int t){
        if(!root)return;
        p+=root->val;
        ans+=m[p-t];
        m[p]++;
        dfs(root->left,t);
        dfs(root->right,t);
        m[p]--;
        p-=root->val;
    }
    int pathSum(TreeNode* root, int t) {
        m[0]=1;
        dfs(root,t);
        return ans;
    }
};