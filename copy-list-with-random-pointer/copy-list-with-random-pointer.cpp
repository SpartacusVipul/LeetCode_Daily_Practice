/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node *headRef = head;
        while (headRef != NULL) {
            Node *nextNode = headRef->next;
            Node *newNode = new Node(headRef->val);
            headRef->next = newNode;
            newNode->next = nextNode;
            headRef = nextNode;
        }

        headRef = head;
        while (headRef != NULL) {
            Node *randomNode = headRef->random;
            Node *copyNode = headRef->next;
            copyNode->random = randomNode ? randomNode->next : NULL;
            headRef = headRef->next->next;
        }
        
        headRef = head;
        Node *copyHead = headRef->next;
        Node *copyNode = copyHead;
        while (headRef != NULL) {
            headRef->next = headRef->next->next;
            copyNode->next = copyNode->next ? copyNode->next->next : NULL;
            headRef = headRef->next;
            copyNode = copyNode->next;
        }
        return copyHead;
    }

};