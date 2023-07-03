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
    void printList(ListNode *head) {
        ListNode *temp = head;
        while (temp != NULL) {
            cout << temp->val << " "; 
            temp = temp->next;
        }
        cout << endl;
    }

    // just create two seperate lists
    // the first list will have all lower values, other all higher values
    // tricky, useful dummynode concept here,
    // highRef, lowRef and new nodes, and two iterators pointing to thsee nodes, 
    // the iterators are used to insert new nodes 
    // iterators are always at the end of the list
    // critical to make next of highRefIter to NULL at the end of the list
    // at the end, make low Iter point to next of highef, 
    // return lowRef next as res
    ListNode* partition(ListNode* head, int x) {
        ListNode *lowRef = new ListNode(0), *lowRefIter = lowRef, *highRef = new ListNode(0), *highRefIter = highRef;
        ListNode *dummy = head;
        while (dummy != NULL) {
            if (dummy->val >= x) {
                highRefIter->next = dummy;
                highRefIter = highRefIter->next;
            } else {
                lowRefIter->next = dummy;
                lowRefIter = lowRefIter->next;
            }
            dummy = dummy->next;
        }
        highRefIter->next = NULL; // very important 
        lowRefIter->next = highRef->next; 
        return lowRef->next;
    }
};