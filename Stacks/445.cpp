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
#define pb push_back
#define vii vector<int>

void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        while(l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        vii answer;
        int valid=0;
        while(s1.size()>0 && s2.size()>0)
        {
            int num1=s1.top();s1.pop();
            int num2=s2.top();s2.pop();
            
            int num=num1+num2+valid;
            int rem=num%10;
            valid=num/10;
            answer.pb(rem);
        }
        while(s1.size()>0)
        {
            int num=s1.top();s1.pop();
            num+=valid;
            int rem=num%10;
            valid=num/10;
            answer.pb(rem);
        }
        while(s2.size()>0)
        {
            int num=s2.top();s2.pop();
            num+=valid;
            int rem=num%10;
            valid=num/10;
            answer.pb(rem);
        }
        if(valid==1)answer.pb(1);
        reverse(answer.begin(),answer.end());
        
        //print(answer);
        ListNode *main=new ListNode();
        ListNode *temp=new ListNode();
        temp->val=answer[0];
        main=temp;
        for(int i=1;i<answer.size();i++)
        {
            ListNode *newNode=new ListNode();
            newNode->val=answer[i];
            temp->next=newNode;
            temp=newNode;
        }
        return main;
    }
};
