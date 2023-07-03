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
    // tricky problem,
    // reverse in groups, if nodes of group size is not present stop
    // using heloper function getKthNode to check if the k nodes exist
    // if exist, then we get kthNode
    // we have to reverse from dummy->next to kth node (including)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *dummyRef = dummy;
        
        while (true) {
            ListNode *kthNode = getKthNode(dummyRef, k);
            // if kth node is not present, then break
            if (kthNode == NULL) {
                break;
            }
            // savinf next node of kth node, 
            // because, when we are reversing from dummy->next to kth node included, 
            // the loop should stop at next node of kth node so that kth node is also reversed
            ListNode *groupNext = kthNode->next;

            // prev is made ot point to kthNode->next, cur is dummyRef->next
            // prev is expected, cur should point to next of kth node at first everytime in the loop
            ListNode *prev = kthNode->next, *cur = dummyRef->next;
            while (cur != groupNext) {
                ListNode *nextNode = cur->next;
                cur->next = prev; 
                prev = cur;  
                cur = nextNode; 
            }
            // at the end of above while loop, the kth node will be the first starting point, 
            // looping till next of kth node, such that all from dummy->next to kthnode are reveresed
            // now, dummyRef was initiallly pointing to start of the node which in the reversed part moved inside 
            // save the dummyRef->next which will be the starting point for the next iteration
            // now dummyRef->next is set to kthNode which became the new starting point
            // after that, dummyRef is made equal to temp from initial, which is the starting point 
            ListNode *temp = dummyRef->next;
            dummyRef->next = kthNode;
            dummyRef = temp;
        }
        return dummy->next;
    }
};