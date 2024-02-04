/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v[505];
    void dfs(TreeNode *rt){
        if(!rt) return;
        int x = rt->val;
        if(rt->left){
            v[x].push_back(rt->left->val);
            v[rt->left->val].push_back(x);
            dfs(rt->left);
        }
        if(rt->right){
            v[x].push_back(rt->right->val);
            v[rt->right->val].push_back(x);
            dfs(rt->right);
        }
    }
    void bfs(int k, int dis, vector<int> &ans){
        queue<pair<int,int>> q;
        q.push({k,0});
        bitset<505> vis;
        vis.reset();
        vis[k]=1;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            if(x.second == dis){
                ans.push_back(x.first);
                continue;
            }
            for(int &i:v[x.first]){
                if(!vis[i]){
                    q.push({i, x.second+1});
                    vis[i]=1;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        dfs(root);
        bfs(target->val, k, ans);
        return ans;
    }
};
