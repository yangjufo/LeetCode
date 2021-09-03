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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        unordered_set<int> val;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if (val.find(k - node->val) != val.end()) {
                return true;
            }
            val.insert(node->val);
            if (node->left) {
                treeQueue.push(node->left);
            }
            if (node->right) {
                treeQueue.push(node->right);
            }
        }
        return false;
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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        vector<int> nums;
        inorder(root, nums);
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                return true;
            }
            if (nums[left] + nums[right] > k) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return inorder(root, k, seen);
    }
    
    bool inorder(TreeNode* root, int k, unordered_set<int>& seen) {
        if (root == NULL) return false;
        if (inorder(root->left, k, seen)) return true;
        if (seen.find(k - root->val) != seen.end()) return true;
        seen.insert(root->val);
        return inorder(root->right, k, seen);
    }
};