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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) {
            return head;
        }
        if (head == NULL) {
            return head;
        }

        int listSize = getListSize(head);
        if (listSize == 1) {
            return head;
        }
        cout << listSize << endl;
        if (k >= listSize) {
            k = k % listSize;
        }
        if (k == 0) {
            return head;
        }
        ListNode *dummy = head;
        for (int i = 0; i < listSize - k - 1; i++) {
            dummy = dummy->next;
        }
        cout << dummy->val << endl;

        ListNode *tempDummy = new ListNode(0);
        tempDummy->next = dummy->next;
        ListNode *newHead = dummy->next;
        dummy->next = NULL;
        while (tempDummy->next != NULL) {
            tempDummy = tempDummy->next;
        }
        tempDummy->next = head;
        return newHead;
    }
};




