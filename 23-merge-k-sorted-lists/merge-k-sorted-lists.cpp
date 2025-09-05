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

     void sortedArr(ListNode* head, multiset<int>& s) {

        ListNode*temp= head;
        while(temp) {
            s.insert(temp->val);
            temp=temp->next;
        }

     }



    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        multiset<int>s;
        for(int i=0;i<lists.size();i++) {
            sortedArr(lists[i],s);
        }
       ListNode* dummy= new ListNode(-1);

       ListNode* temp = dummy;

       for (auto it : s) {
         ListNode* newNode= new ListNode(it);
         temp->next=newNode;
         temp = newNode;
       }
       return dummy->next;

    }
};