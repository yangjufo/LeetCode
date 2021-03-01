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
    int firstMin = INT_MAX, secondMin = INT_MAX;
    bool firstSet = false, secondSet = false;
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) return -1;
        if (root->val <= firstMin) {
            if (firstSet && root->val != firstMin) {                
                secondSet = true;
                secondMin = firstMin;
            }
            
            firstSet = true;            
            firstMin = root->val;
        } else if (root->val <= secondMin) {
            secondSet = true;
            secondMin = root->val;
        }
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);
        return secondSet ? secondMin : -1;
    }
};

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
    int min1, ans = INT_MAX;
    bool found = false;
    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val;
        dfs(root);
        return found ? ans : -1;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        
        if (root->val > min1 && root->val <= ans) {
            ans = root->val;
            found = true;
        }
        else if (min1 == root->val) {
            dfs(root->left);
            dfs(root->right);
        }
    }
    
};