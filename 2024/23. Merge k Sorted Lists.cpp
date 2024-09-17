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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(), *prev = dummy;
        while (true) {
            ListNode** next = NULL;
            for (ListNode*& head : lists) {
                if (head == NULL) {
                    continue;
                }
                if (next == NULL || head->val < (*next)->val) {
                    next = &head;
                }
            }
            if (next == NULL) {
                break;
            }
            prev->next = *next;
            prev = *next;
            *next = (*next)->next;
        }
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        while (lists.size() > 1) {
            vector<ListNode*> next;
            for (int i = 0; i + 1 < lists.size(); i += 2) {
                next.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            }
            if (lists.size() % 2 == 1) {
                next.push_back(lists.back());
            }
            lists = next;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(), *prev = dummy;
        while (left != NULL || right != NULL) {
            if (left == NULL || (right != NULL && left->val > right->val)) {
                prev->next = right;
                prev = right;
                right = right->next;
            } else {
                prev->next = left;
                prev = left;
                left = left->next;
            }
        }
        return dummy->next;
    }
};