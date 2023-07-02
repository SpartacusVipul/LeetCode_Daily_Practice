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
    // maintain a dummy node point to head
    // this dummy node is used to handle edge cases in all linkedlist
    // problems
    // Now, dummy is prevPointer, dummy->next is currentPointer
    // iterate till left - 1 indices, such that current points to 
    // left index, prev is left - 1
    // once currentPointer is at left index, reverse 
    // the list from currentPointer till right - left + 1
    // create a new prev Node, which will be NULl initially
    // reverse the list, till index right - left  + 1
    // once this is reverse, 
    // the prevPointer is still pointing to old next from 
    // original list, but this old next is the last node in the 
    // reversed part, so the prevPointer->next->next = NULL 
    // at this point, the currentPointer is pointing to old next 
    // of the head of the reversed list
    // so first make prevPointer->next->next = currentPointer
    // prevPointer->next = prev (which became the new head)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevPointer = dummy, *currentPointer = dummy->next; 
        // iterate such that currentPointer is at left index
        // prevPointer is just before current Pointer
        for (int i = 0; i < left - 1; i++) {
            currentPointer = currentPointer->next;
            prevPointer = prevPointer->next;
        } 

        // new prev Node, which is NUll and used to reverse the list
        // iterate till right - left + 1, 
        // at the end of loop, currentPointer will be outside 
        // the reversed part, to which we need to connect the 
        // end of the reversed part
        // at end of loop, prev is pointing to new head for the 
        // reversed part 
        ListNode *prev = NULL;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode *nextNode = currentPointer->next;
            currentPointer->next = prev;
            prev = currentPointer;
            currentPointer = nextNode;
        }

        // at this point, prevPointer is a node just before 
        // the section which needs to be reversed 
        // prevPointer->next->next is now pointing to NULL
        // so, make prevPointer->next->next to point to currentPointer
        // and deteach and attach its next to prev
        prevPointer->next->next = currentPointer;
        prevPointer->next = prev;
        return dummy->next;
    }
};

