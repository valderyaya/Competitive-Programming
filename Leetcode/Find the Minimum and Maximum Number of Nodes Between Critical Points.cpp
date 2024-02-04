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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=0,fst=-1,last=-1,mn=1e9,pre=-1;
        while(head){
            if(pre!=-1 && head->next && (pre>head->val&&head->val<head->next->val || pre<head->val&&head->val>head->next->val) ){
                if(fst==-1) fst=idx;
                if(last!=-1) mn=min(mn,idx-last);
                last = idx;
            }
            ++idx;
            pre = head->val;
            head = head->next;
        }
        vector<int> ret;
        ret.emplace_back(mn==1e9?-1:mn);
        ret.emplace_back(mn==1e9?-1:last-fst);
        return ret;
    }
};
