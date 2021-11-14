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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int index = 1;
        ListNode* res = head, *prev = head;
        int total = 0;
        ListNode* node = head;
        while(node != NULL) {
            node = node->next;
            total++;
        }
        while (head != NULL) {
            if ((index % 2 == 0 && total >= index) || (total < index && total % 2 == 0)) {
                ListNode* cPrev = head, *tail = head, *next = NULL;
                head = head->next;
                for (int i = 1; i < index && head != NULL; i++) {                    
                    next = head->next;
                    head->next = cPrev;                    
                    cPrev = head;                    
                    head = next;
                }
                prev->next = cPrev;                
                tail->next = next;                  
                prev = tail;
            } else {
                for (int i = 1; i <= index && head != NULL; i++) {
                    prev = head;
                    head = head->next;                    
                }
            }      
            total -= index;
            index++;
        }
        return res;
    }    
};