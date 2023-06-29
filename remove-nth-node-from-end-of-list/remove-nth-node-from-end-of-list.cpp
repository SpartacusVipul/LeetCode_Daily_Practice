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
    // very critical to maintain a dummy pointer
    // the dummy's next is pointing to head
    // first and second point to dummy
    // first is iterated n + 1 times, (because we are at the dummy within the List, we will traverse n nodes)
    // second is at dummy 
    // now till first doesnt reach end, we update both pointers
    // make second->next to point to second->next->next (to delete n th node from end) 
    // return dummy->next which is new head, it handles case with only element 
    // returning head, will not work in single element case
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *first = dummy, *second = dummy;
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        // very important to return dummy->next
        return dummy->next;
    }
};