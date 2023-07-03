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
    // initial plan is find the kth node from the end
    // make its parent point to null, and traverse it and when it reaches null, make it point to head
    int getListSize(ListNode *head) {
        ListNode *temp = head;
        int size = 0;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }
    // maybe triicky
    // first calculate the length of the list
    // then check if k >= len, if yes, take mod len to know how many rotations to perform
    // once that is done, iterate oveer the list listize - k - 1 times to go the the node,
    // the next node of this node is the new head
    // save the new head, make the next of the current node to NULL(closing the list here)
    // update dummy to newHead and iterate till next null is found, once there, make next point to head,
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int listSize = getListSize(head);
        if (listSize == 1) return head;

        if (k >= listSize) k = k % listSize;
        if (k == 0) return head;

        ListNode *dummy = head;
        for (int i = 0; i < listSize - k - 1; i++) {
            dummy = dummy->next;
        }
        ListNode *newHead = dummy->next; // saving new head
        dummy->next = NULL; // closing list jusst before new head
        dummy = newHead; // updating dummy to new head, and iterating till next null is encountered
        while (dummy->next != NULL) {
            dummy = dummy->next;
        }
        dummy->next = head; // making last node point to head, instead of NULL
        return newHead;
    }
};




