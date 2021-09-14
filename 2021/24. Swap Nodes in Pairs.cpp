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
    ListNode* swapPairs(ListNode* head) {        
        ListNode* curr = head, *prev = NULL;        
        while (curr != NULL && curr->next != NULL) {
            ListNode *neighbor = curr->next, *next = neighbor->next;
            neighbor->next = curr;
            curr->next = next;
            if (prev == NULL) {
                head = neighbor;                
            } else {
                prev->next = neighbor;
            }
            prev = curr;
            curr = next;
        }
        return head;
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(), *prev = dummy;
        dummy->next = head;
        while (head != NULL && head->next != NULL) {
            ListNode* second = head->next, *next = second->next;            
            prev->next = second;
            second->next = head;
            head->next = next;            
            prev = head;
            head = next;
        }
        return dummy->next;
    }
};