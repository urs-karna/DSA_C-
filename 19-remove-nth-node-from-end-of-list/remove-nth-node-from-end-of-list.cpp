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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL ){
             return head;
        }
        if( head->next==NULL && n==1) {
            return NULL;
        }

         ListNode* temp=head;
          int cnt=0;
         while(temp != NULL) {
            cnt++;
            temp=temp->next;

         }
         
        if(cnt == n) {
           ListNode* newHead=head-> next;
           delete head;
           return newHead;
        }
         temp=head;
         ListNode* prev=NULL;
         ListNode* front=temp->next;
         cnt = cnt-n;
         while (temp != NULL) {
               if(cnt==0){
                prev->next=front;
                temp->next=nullptr;
                 delete temp;
                return head;
               }
               prev=temp;
               temp=temp->next;
               front = temp->next;
               cnt--;
         }
         return head;
    }
};