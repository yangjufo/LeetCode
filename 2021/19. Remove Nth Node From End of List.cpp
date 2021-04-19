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
    ListNode* removeNthFromEnd(ListNode* head, int n) {       
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }        
        ListNode* toDelete = NULL;
        if (fast == NULL) {       
            toDelete = head;
            head = head->next;
        } else {
            while (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }            
            toDelete = slow->next;
            slow->next = toDelete->next;
        }
        
        delete toDelete;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = head;
        head = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            head = head->next;
        }
        
        ListNode* toDelete = head->next;        
        head->next = toDelete->next;
        delete toDelete;
        
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n && fast != NULL; i++) {
            fast = fast->next;
        }
        ListNode *dummy = new ListNode(), *prev = dummy;     
        dummy->next = head;
        while (fast != NULL) {
            prev = prev->next;
            fast= fast->next;
        }
        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        head = dummy->next;
        delete dummy;
        return head;
    }
};