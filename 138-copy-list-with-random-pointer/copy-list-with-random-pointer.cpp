/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNodeBtw(Node* head) {

        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            Node* nextNode = temp->next;

            temp->next = newNode;
            newNode->next = nextNode;
            temp = nextNode;
        }
    }

    void connectRandomPtr(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* copyList(Node* head) {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* temp = head;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        // if(head==NULL || head->next==NULL) return head;
        insertNodeBtw(head);

        connectRandomPtr(head);

        return copyList(head);
    }
};