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
    ListNode *getKthNode(ListNode *head, int k) {
        ListNode *headRef = head;
        for (int i = 0; i < k && headRef != NULL; i++) {
            headRef = headRef->next;
        }
        return headRef;
    }

    void printList(ListNode *head) {
        ListNode *headRef = head;
        while (headRef != NULL) {
            cout << headRef->val << " ";
            headRef = headRef->next;
        }
        cout << endl;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *dummyRef = dummy;
        
        while (true) {
            ListNode *kthNode = getKthNode(dummyRef, k);
            if (kthNode == NULL) {
                break;
            }
            ListNode *groupNext = kthNode->next;
            ListNode *prev = kthNode->next, *cur = dummyRef->next;
            while (cur != groupNext) {
                ListNode *nextNode = cur->next;
                cur->next = prev; 
                prev = cur;  
                cur = nextNode; 
            }
            
            ListNode *temp = dummyRef->next;
            dummyRef->next = kthNode;
            dummyRef = temp;
        }
        return dummy->next;
    }
};