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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {            
            int i = 0;
            ListNode* subPrev = NULL, *firstNode = curr;
            for (; i < k && curr != NULL; i++) {
                ListNode* next = curr->next;
                curr->next = subPrev;
                subPrev = curr;                
                curr = next;
            }
            if (i < k) {
                ListNode* tmpPrev = NULL;
                while (subPrev != NULL) {
                    ListNode* next = subPrev->next;
                    subPrev->next = tmpPrev;
                    tmpPrev = subPrev;
                    subPrev = next;
                }
                subPrev = firstNode;
            }
            if (prev == NULL) {
                head = subPrev;
            } else {
                prev->next = subPrev;
            }
            prev = firstNode;                                    
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
    ListNode* reverseKGroup(ListNode* head, int k) {        
        ListNode *dummy = new ListNode(), *prevEnd = dummy, *curr = head;
        int count = 0;
        while (curr != NULL) {
            count++;            
            if (count % k == 0) {
                ListNode* next = curr->next;                
                curr->next = NULL;
                prevEnd->next = reverse(head);
                prevEnd = head;
                head = next;
                curr = next;                
          } else {
                curr = curr->next;
            }
        }        
        prevEnd->next = head;
        return dummy->next;
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