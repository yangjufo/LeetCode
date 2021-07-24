/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* insertNode = new Node(insertVal);
        if (head == NULL) {            
            insertNode->next = insertNode;
            return insertNode;
        }
        Node* curr = head;
        do {    
           if (curr->next == head
              || (curr->val < curr->next->val && curr->val <= insertVal && curr->next->val >= insertVal)
              || (curr->val > curr->next->val && (insertVal >= curr->val || insertVal <= curr->next->val))
              ) {
                insertNode->next = curr->next;
                curr->next = insertNode;                
                break;
            }
            curr = curr->next;
        } while (curr != head);
        
        return head;
    }
};