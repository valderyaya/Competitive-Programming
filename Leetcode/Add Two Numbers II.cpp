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
    vector<int> a,b;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = l1;
        //cout<<(h?1:0)<<endl;
        while(h) {a.push_back(h->val), h=h->next;}
        //cout<<a.size()<<endl;
        h = l2;
        while(h) {b.push_back(h->val), h=h->next;}
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size()) swap(a,b);
        for(int i=0;i<a.size();++i){
            if(i<b.size()) a[i]+=b[i];
            if(a[i]>=10){
                if(i+1<a.size()) a[i+1]+=a[i]/10;
                else a.push_back(a[i]/10);
                a[i]%=10;
            }
        }
        int x = a[a.size()-1];
        if(x>=10){
            a[a.size()-1] = x%10;
            a.push_back(x/10);
        }
        reverse(a.begin(), a.end());
        ListNode *ret = new ListNode();
        ListNode *p = ret;
        for(int i=0;i<a.size();++i){
            p->val = a[i];
            if(i+1<a.size()){
                p->next = new ListNode();
                p = p->next;
            }
        }
        return ret;
    }
};
