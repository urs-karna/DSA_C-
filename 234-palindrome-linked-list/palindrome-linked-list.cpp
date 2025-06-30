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
    bool isPalindrome(ListNode* head) {
            if(head==NULL || head->next==NULL) return true;
         
             ListNode* slow=head;
             ListNode* fast=head;
             while(fast != NULL && fast-> next != NULL) {
                slow=slow->next;
                fast=fast->next->next;
             }

              ListNode* temp = slow;
              ListNode* prev = NULL;
             ListNode* front=NULL;
              while(temp!= NULL) {

                front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front; 
              }

         ListNode* newHead= prev;
          temp=head;

        while(newHead != NULL) {
            if( temp->val != newHead->val ) {
                return false;
            }
            temp=temp->next;
            newHead=newHead-> next;
        }
        return true;

    }
};