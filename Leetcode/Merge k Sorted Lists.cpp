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
class Solution {
public:
    vector<vector<int>> lst;
    vector<int> dfs(int l,int r){
        if(l>=r){
            if(l==r) return lst[l];
            vector<int> v;
            return v;
        }
        int mid=(l+r)>>1;
        vector<int> L=dfs(l,mid);
        vector<int> R=dfs(mid+1,r);
        vector<int> v;
        for(int i=0,j=0;i<L.size()||j<R.size();){
            if(j>=R.size()||(i<L.size()&&L[i]<=R[j])) v.emplace_back(L[i++]);
            else v.emplace_back(R[j++]);
        }
        return v;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i=0;i<lists.size();++i){
            if(lists[i]==NULL) continue;
            vector<int> v;
            while(lists[i]){
                v.emplace_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
            lst.emplace_back(v);
        }
        vector<int> v=dfs(0,lst.size()-1);
        ListNode *head=NULL, *res=NULL, *prv=NULL;
        for(auto &i:v){
            head=new ListNode(i);
            if(prv) prv->next = head;
            prv = head;
            if(!res) res=head;
            head = head->next;
        }
        return res;
    }
};
