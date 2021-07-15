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
    ListNode* plusOne(ListNode* head) {        
        head = reverse(head);
        ListNode* curr = head;
        int rem = 0;
        do {
            rem = (curr->val >= 9 ? 1 : 0);
            curr->val = (curr->val + 1) % 10;  
            curr = curr->next;
        } while (curr != NULL && rem > 0);
        head = reverse(head);
        if (rem > 0) {
            ListNode* newHead = new ListNode(rem);
            newHead->next = head;
            head = newHead;
        }
        
        return head;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;            
        }
        return prev;
    }
};

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
    ListNode* plusOne(ListNode* head) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* notNine = sentinel;
        while (head != NULL) {
            if (head->val != 9) notNine = head;
            head = head->next;
        }
        
        notNine->val += 1;
        notNine = notNine->next;
        while (notNine != NULL) {
            notNine->val = 0;
            notNine = notNine->next;
        }
        
        return sentinel->val > 0 ? sentinel : sentinel->next;
        
    }
};