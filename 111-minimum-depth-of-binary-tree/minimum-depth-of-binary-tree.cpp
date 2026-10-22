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
    set<int> s;
    int solve(TreeNode* root){
        if(!root)return INT_MAX;
        int l=solve(root->left);
        int r=solve(root->right);
        int mm=min(l,r);
        if(mm==INT_MAX)mm=0;
        int mn=1+mm;
        return mn;
        
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return solve(root);

       
    }

};