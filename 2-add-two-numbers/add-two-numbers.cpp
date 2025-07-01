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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
      ListNode* dummy=new ListNode(-1);
        ListNode* current=dummy;
        ListNode* t1=list1;
        ListNode* t2=list2;
        int carry=0;

        while( t1 != NULL || t2 != NULL) {

            int sum=carry;

            if(t1) sum +=t1->val;
            if(t2) sum +=t2->val;

            ListNode* newNode= new ListNode(sum%10);
             carry=sum/10;

            current->next= newNode;
            current= newNode;

            if(t1) t1=t1->next;
            if(t2) t2=t2->next;

        }

     if(carry) {
        ListNode* newNode= new ListNode(1);
        current->next=newNode;
     }

     return dummy->next;
        
    }  
    
};