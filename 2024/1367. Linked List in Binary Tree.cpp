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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSame(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        return head->val == root->val && (isSame(head->next, root->left) ||
                                          isSame(head->next, root->right));
    }
    bool isSubPath(ListNode* head, ListNode* node, TreeNode* root) {
        if (node == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        return isSame(node, root) ||
               isSubPath(head, head, root->left) ||
               isSubPath(head, head, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPath(head, head, root);
    }
};