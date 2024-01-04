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
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;
            node = clone->next;
        }

        node = head;
        while (node != NULL) {
            node->next->random = node->random == NULL ? NULL : node->random->next;
            node = node->next->next;
        }
        Node* cloneHead = head->next;
        Node* oldNode = head, *cloneNode = head->next;
        while (oldNode != NULL) {
            oldNode->next = oldNode->next->next;
            cloneNode->next = cloneNode->next == NULL ? NULL : cloneNode->next->next;
            oldNode = oldNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};