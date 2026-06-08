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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
           int n=q.size();
           long long f,l;
            long long mm=q.front().second;
           for(int i=0;i<n;i++){
            TreeNode* no=q.front().first;
            long long id=q.front().second-mm;
            q.pop();
            if(i==0)f=id;
            if(i==n-1)l=id;
            if(no->left)q.push({no->left,(long long)2*id+1});
            if(no->right)q.push({no->right,(long long)2*id+2});
           }
           ans=max(ans,l-f+1);
        }
        return ans;

    }
};