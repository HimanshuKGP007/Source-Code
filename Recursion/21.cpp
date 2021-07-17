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

ListNode* joinFunc(ListNode* l1,ListNode* l2)
{
    if(l1->val <= l2->val)
    {
        if(l1->next!=NULL)
            l1->next=joinFunc(l1->next,l2);
        else l1->next=l2;
        
        return l1;
    }
    else
    {
        if(l2->next!=NULL)
            l2->next=joinFunc(l1,l2->next);
        else l2->next=l1;
        
        return l2;
    }
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2!=NULL)return l2;
        if(l1!=NULL && l2==NULL)return l1;
        if(l1==NULL && l2==NULL)return NULL;
        ListNode *main=joinFunc(l1,l2);
        return main;
    }
};
