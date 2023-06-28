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
    // dummy is an important concept here
    // this is required becausem, 
    // here we are not creating new list, just updating dummy to point to 
    // appropriate node in the list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ref = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2-> val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        // we are breaking out of while loop implies that 
        // atleast one of list1 or list2 is NULL
        // it is possible both are null, but in that case also, we just set dummy->next to null in the else case
        if (list1 != NULL) { // implies list2 is NULL
            dummy->next = list1; 
        } else  { // implies list1 is NULL
            dummy->next = list2;
        }
        return ref->next;
    }
};