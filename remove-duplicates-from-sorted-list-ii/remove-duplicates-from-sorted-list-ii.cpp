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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy; // dummy is used as a reference for the head to be returned in the end
        // when head is set to dummy, there are atleast three elements in this list,
        // if list was emtpty or a single element then it would have returned at the top
        // we are adding dummy infront of head, so three elements in the list
        // there fore head->next != NULL and head->next->next is also not NULL
        while (head->next != NULL && head->next->next != NULL) {
            if (head->next->val == head->next->next->val) { 
                // if initially the second and thrid elements have same value,  
                int val = head->next->val;
                // assume 0 1 2 2 2 2 3
                // then head is intially at 0, 
                // head->next->val = 1 not equal to head->next->next->val
                // so regular increment
                // now, head is at 1, head->next is at 2, head->next->next is at 2 
                // there fore since head is at 1, we are setting head->next = head->next->next
                // so, overwriting the pointer to 2 to poitner to next of other 2
                // Note, we are not updating head here, just updating head->next
                // above is very important note
                while (head->next != NULL && head->next->val == val) { // here in the first iteration iteself
                    head->next = head->next->next; // head->next was the first time the duplicate value was found
                    // so, head->next is set to head->next->next, so updating head->next so removing duplicate like this
                    // head->next->next is at some point not equal to val, and head->next is set to that new val duplicate is removed
                    // this is tricky update, as head is not moving, what head is pointing to is moving through next->next
                }            
            } else {
                head = head->next;
            }
        }

        return dummy->next;
    }
};