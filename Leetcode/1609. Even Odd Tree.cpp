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
    vector<int> v[100001];
    int dep = 0;
    void dfs(TreeNode *rt, int lev){
        dep = max(dep, lev);
        v[lev].emplace_back(rt->val);
        if(rt->left) dfs(rt->left, lev+1);
        if(rt->right) dfs(rt->right, lev+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root, 0);
        bool ans = 1;
        // for(int i=0;i<=dep;++i)
        //     for(int j=0;j<v[i].size();++j) cout<<v[i][j]<<" \n"[j==v[i].size()-1];
        for(int i = 0; i <= dep; ++i)
            if(i & 1){
                for(int j = 0; j < v[i].size(); ++j){
                    if(v[i][j] & 1){
                        ans = 0;
                        break;
                    }
                    if(j && v[i][j] >= v[i][j-1]){
                        ans = 0;
                        break;
                    }
                }
            }else{
                for(int j = 0; j < v[i].size(); ++j){
                    if(v[i][j] % 2 == 0){
                        ans = 0;
                        break;
                    }
                    if(j && v[i][j] <= v[i][j-1]){
                        ans = 0;
                        break;
                    }
                }
            }
        return ans;
    }
};
