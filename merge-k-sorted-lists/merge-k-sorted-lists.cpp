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

    // beautiful solution, 
    // the problems asks us to merge k sorted lists 
    // time complexity is klog(lists.size())
    // using divide and conquer number of merges is significantly reduced
    // trick while mergin is to use a dummy node 
    ListNode * merge(ListNode* left, ListNode* right) {
        ListNode * dummy = new ListNode(0);
        ListNode * ref = dummy;
        while (left != NULL || right != NULL) {
            if (left != NULL && right != NULL) {
                if (left->val < right->val) {
                    dummy->next = left;
                    left = left->next;
                } else {
                    dummy->next = right;
                    right = right->next;
                }
            } else if (left != NULL) {
                dummy->next = left;
                left = left->next;
            } else if (right != NULL) {
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        // below commented code is better 
        // while (left != NULL && right != NULL) {
        //     if (left -> val < right-> val) {
        //         dummy->next = left;
        //         left = left->next;
        //     } else {
        //         dummy->next = right;
        //         right = right->next;
        //     }
        //     dummy = dummy->next;
        // }
        // if (left != NULL) {
        //     dummy->next = left;
        // } else {
        //     dummy->next = right;
        // }
        return ref->next;
    }

    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        }
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = mergeHelper(lists, start, mid);
        ListNode* right = mergeHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeHelper(lists, 0, lists.size() - 1);
    }

    

};