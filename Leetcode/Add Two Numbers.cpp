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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode();
        ListNode *res=ans;
        int x=0;
        while(l1!=nullptr||l2!=nullptr){
            if(l1==nullptr){
                ans->val=l2->val+x;
                if(ans->val>9) x=1,ans->val-=10;
                else x=0;
                if(l2->next!=nullptr){
                    ans->next=new ListNode();
                    ans=ans->next;
                }
                l2=l2->next;
            }else if(l2==nullptr){
                ans->val=l1->val+x;
                if(ans->val>9) x=1,ans->val-=10;
                else x=0;
                if(l1->next!=nullptr){
                    ans->next=new ListNode();
                    ans=ans->next;
                }
                l1=l1->next;
            }else{
                ans->val=l1->val+l2->val+x;
                if(ans->val>9) x=1,ans->val-=10;
                else x=0;
                if(l1->next!=nullptr||l2->next!=nullptr){
                    ans->next=new ListNode();
                    ans=ans->next;
                }
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(x){
            ans->next=new ListNode();
            ans=ans->next;
            ans->val=1;
        }
        return res;
    }
};
