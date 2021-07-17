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
int valid=1;
ListNode *headNode;
void recur(ListNode *end)
{
    if(end->next!=NULL)
    {
        recur(end->next);
    }
    if(end->val==headNode->val)headNode=headNode->next;
    else valid=0;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        valid=1;
        headNode=head;
        recur(head);   
        return valid;
    }
};
