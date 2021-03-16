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
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        
        stack<TreeNode*> treeStack;
        int num = 0, flag = 1;
        TreeNode* root = NULL;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (s[i - 1] != ')') {
                    TreeNode* node = new TreeNode(flag * num);
                    flag = 1;
                    num = 0;
                    treeStack.push(node);
                    if (root == NULL) {
                        root = node;
                    }                
                }
            } else if (s[i] == ')') {
                TreeNode* node = NULL;
                if (s[i - 1] != ')') {
                    node = new TreeNode(flag * num);
                    flag = 1;
                    num = 0;                    
                } else {
                    node = treeStack.top();
                    treeStack.pop();
                }
                if (treeStack.top()->left == NULL) {
                    treeStack.top()->left = node;                        
                } else {
                    treeStack.top()->right = node;                        
                }
            } else {
                if (s[i] == '-') {
                    flag = -1;
                } else {
                    num = num * 10 + (s[i] - '0');
                }
            }
        }        
        return root == NULL ? new TreeNode(flag * num) : root;
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
    TreeNode* str2tree(string s) {        
        stack<TreeNode*> treeStack;        
        for (int i = 0, j = i; i < s.length(); i++, j = i) {
            if (s[i] == ')') {
                treeStack.pop();
            } else if (isdigit(s[i]) || s[i] == '-') { 
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    i++;
                }
                TreeNode* node = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!treeStack.empty()) {
                    TreeNode* parent = treeStack.top();
                    if (parent->left == NULL) {
                        parent->left = node;                    
                    } else {
                        parent->right = node;
                    }                    
                }
                treeStack.push(node);                
            }
        }
        return treeStack.empty() ? NULL : treeStack.top();
    }       
};