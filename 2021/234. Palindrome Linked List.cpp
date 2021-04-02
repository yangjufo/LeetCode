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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }        
        ListNode* rightHead = reverse(slow->next);        
        slow->next = NULL;
        while (rightHead != NULL && head != NULL) {            
            if (rightHead->val != head->val) return false;
            rightHead = rightHead->next;
            head = head->next;
        }
        return true;        
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
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return check(head);
    }
    
    bool check(ListNode* curr) {
        if (curr == NULL) return true;
        bool isPal = check(curr->next) && (left->val == curr->val);
        left = left->next;
        return isPal;
    }
};