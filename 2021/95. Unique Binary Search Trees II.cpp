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
    vector<TreeNode*> generateTrees(int n) {        
        return generateSubTrees(1, n);
    }
    
    vector<TreeNode*> generateSubTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }              
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSub = generateSubTrees(start, i - 1);
            vector<TreeNode*> rightSub = generateSubTrees(i + 1, end);
            
            for (TreeNode* leftRoot : leftSub) {
                for (TreeNode* rightRoot : rightSub) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    res.push_back(root);
                }
            }
        }
        
        return res;
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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
    
    vector<TreeNode*> build(int left, int right) {
        if (left > right) return { NULL };
        vector<TreeNode*> res;
        for (int i = left; i <= right; i++) {            
            for (TreeNode* lChild : build(left, i - 1)) {
                for (TreeNode* rChild: build(i + 1, right)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lChild;
                    root->right = rChild;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};