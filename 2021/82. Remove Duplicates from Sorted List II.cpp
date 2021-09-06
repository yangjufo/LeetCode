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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(), *prev = dummy;
        while (head != NULL) {
            bool dup = false;
            while (head->next != NULL && head->val == head->next->val) {
                dup = true;
                head = head->next;
            }                        
            if (!dup) {
                prev->next = head;
                prev = prev->next;                
            }
            head = head->next;
        }
        prev->next = NULL;
        return dummy->next;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *dummy = new ListNode(), *prev = dummy;
        dummy->next = head;
        while (head != NULL) {
            int currVal = head->val;
            if (head->next != NULL && head->next->val == currVal) {
                while (head != NULL && head->val == currVal) {
                    ListNode* toDelete = head;
                    head = head->next;
                    delete toDelete;
                }
                prev->next = head;                
            } else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
        }
        head = dummy->next;
        delete dummy;
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
    ListNode* deleteDuplicates(ListNode* head) {        
        ListNode* dummy = new ListNode(), *prev = dummy, *headPrev = dummy;
        dummy->next = head;
        int count = 0;
        while (head != NULL) {
            ListNode* next = head->next;
            if (head->val != prev->next->val) {
                if (count > 1) {
                    prev->next = head;
                    count = 1;
                } else {
                    prev = headPrev;
                }
            } else {
                count++;
            }
            headPrev = head;
            head = next;            
        }
        if (count > 1) {
            prev->next = head;
        }
        return dummy->next;
    }
};