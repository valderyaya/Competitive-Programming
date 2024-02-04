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
    vector<int> v[2001];
    int mx;
    void dfs(TreeNode *rt,int d){
        mx=max(mx,d);
        v[d].push_back(rt->val);
        if(rt->left) dfs(rt->left,d+1);
        if(rt->right) dfs(rt->right,d+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        dfs(root,0);
        for(int i=0;i<=mx;++i){
            if(i&1) reverse(v[i].begin(),v[i].end());
            ret.push_back(v[i]);
        }
        return ret;
    }
};
