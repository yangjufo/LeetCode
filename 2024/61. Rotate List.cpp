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
    void print(ListNode* head) {
        while (head != NULL) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int len = 0;
        ListNode* node = head;
        while (node != NULL) {
            node = node->next;
            len += 1;
        }
        k %= len;
        if (k == 0) {
            return head;
        }
        head = reverse(head);
        ListNode* prev = head;
        for (int i = 0; i + 1 < k; i++) {
            prev = prev->next;
        }
        ListNode* next = prev->next;
        prev->next = NULL;
        prev = head;
        head = reverse(head);
        next = reverse(next);
        prev->next = next;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int n = 1;
        ListNode* oldTail = head;
        for(; oldTail->next != NULL; n += 1) {
            oldTail = oldTail->next;
        }
        oldTail->next = head;
        ListNode* newTail = head;
        for (int i = 1; i < n - k % n; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};