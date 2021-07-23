/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return dfs(head).first;
    }
    
    pair<Node*, Node*> dfs(Node* head) {        
        Node *curr = head, *tail = head;
        while (curr != NULL) {            
            if (curr->child != NULL) {
                auto ht = dfs(curr->child);
                curr->child = NULL;                
                ht.second->next = curr->next;
                if (curr->next != NULL) {
                    curr->next->prev = ht.second;
                }
                curr->next = ht.first;
                ht.first->prev = curr;                     
                curr = ht.second;
            }
            tail = curr;
            curr = curr->next;            
        }
        return {head, tail};
    }
};