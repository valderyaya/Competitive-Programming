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
    int ans;
    void dfs(TreeNode *rt,int d){
        ans=max(ans,d);
        if(rt->left) dfs(rt->left,d+1);
        if(rt->right) dfs(rt->right,d+1);
    }
    int maxDepth(TreeNode* root) {
        if(root) dfs(root,1);
        return ans;
    }
};
