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
    ListNode* rev(ListNode *head){
        ListNode* temp =head;
        ListNode* prev=NULL;

        while(temp != NULL) {
            ListNode* front= temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
        
    

    ListNode* FindKthNode(ListNode* temp,int k){
       k--;
       while(temp!= NULL && k>0) {
        temp=temp->next;
        k--;
       }
       return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
    return head;  // No reversal needed
}

        ListNode* temp= head;
        ListNode* prevNode=NULL;

        while(temp != NULL) {
        ListNode* kthNode=FindKthNode(temp,k);
         if(kthNode == NULL) {

            if(prevNode)  prevNode->next=temp;
            break;
         }


        ListNode* nextNode=kthNode->next;
        kthNode->next=NULL;
        rev(temp);

        if(temp==head) {
            head=kthNode;
        }
        else {
            prevNode->next=kthNode;
        }

        prevNode=temp;
        temp=nextNode;
        }
        return head;
   
    }
};