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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        int size = 0;
        ListNode* runner = head;

        while (runner != NULL) {
            runner = runner->next;
            size += 1;
        }

        return inorderHelper(0, size - 1, &head);
    }

    TreeNode* inorderHelper(int start, int end, ListNode** head) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* left = inorderHelper(start, mid - 1, head);

        TreeNode* treeNode = new TreeNode((*head)->val);
        treeNode->left = left;
        *head = (*head)->next;

        TreeNode* right = inorderHelper(mid + 1, end, head);
        treeNode->right = right;

        return treeNode;
    }
};