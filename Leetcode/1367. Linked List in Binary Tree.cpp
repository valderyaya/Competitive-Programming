/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> v, f;
    bool dfs(TreeNode *rt, int fp){
        if(!rt) return 0;
        while(~fp && rt->val != v[fp+1]) fp=f[fp];
        if(rt->val == v[fp+1]) ++fp;
        if(fp == v.size() - 1) return 1;
        return dfs(rt->left, fp) | dfs(rt->right, fp);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return 0;
        for(ListNode* node = head; node; node = node->next) v.push_back(node->val);
        f.resize(v.size());
        int fp = -1; f[0] = fp;
        for(int i = 1; i < v.size() - 1; ++i){
            while(~fp && v[i] != v[fp+1]) fp = f[fp];
            if(v[i] == v[fp + 1]) ++fp;
            f[i] = fp;
        }
        return dfs(root, -1);
    }
};
