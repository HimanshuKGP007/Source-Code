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

int target;
ListNode* calc(ListNode *head)
{
    if(head->next!=NULL)
    {
        if(head->next->val!=target)
        {
            head->next=calc(head->next);
        }
        else
        {
            ListNode *temp=head->next;
            while(temp!=NULL && temp->val==target)temp=temp->next;
            if(temp!=NULL)
            {
                head->next=temp;
                temp=calc(temp);
            }
            else head->next=NULL;
        }
    }
    return head;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val)head=head->next;
        if(head==NULL)return NULL;
        else 
        {
            target=val;
            return calc(head);
        }
    }
};
