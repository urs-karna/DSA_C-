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

    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL) return NULL;
        if(k==0) return head;
        ListNode* temp=head;
        ListNode* prevNode=NULL;
         int d=0;
        while(temp != NULL) {
            d++;
            temp=temp->next;
        }
        
        k= k%d;
        ListNode* tail=head;
       while(tail->next !=NULL) {
       tail=tail->next;
       }

       tail->next=head;

       temp=head;
       int dist=d-k;
       while(temp !=NULL) {
        dist--;
        if(dist==0) break;
        temp=temp->next;
       }
         head=temp->next;
         temp->next=NULL;

        return head;
    }

};