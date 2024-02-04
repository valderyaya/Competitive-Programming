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
        queue<pair<TreeNode*,int>> q;
        int mx=0;
        if(root) q.push({root,1});
        while(!q.empty()){
            int l=q.front().second, r=q.back().second, sz=q.size();
            mx=max(mx,r-l+1);
            for(int i=0;i<sz;++i){
                int x=q.front().second - l + 1;
                if(q.front().first->left) q.push({q.front().first->left, x<<1});
                if(q.front().first->right) q.push({q.front().first->right,x<<1|1});
                q.pop();
            }
        }
        return mx;
    }
};
