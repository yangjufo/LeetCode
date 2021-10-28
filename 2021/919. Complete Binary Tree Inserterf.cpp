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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> parents;
    int levelSize = 1;
    CBTInserter(TreeNode* root) {
        this->root = root;
        levelSize = 1;
        parents.push(root);        
        while (parents.size() >= levelSize) {
            int i = 0;
            for (; i < levelSize; i++) {
                TreeNode* node = parents.front();                
                if (node->left != NULL) {
                    parents.push(node->left);
                }
                if (node->right != NULL) {
                    parents.push(node->right);
                }
                if (node->left != NULL && node->right != NULL) {
                    parents.pop();
                } else {
                   break; 
                }
            }
            if (i < levelSize) {
                break;
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val), *parent = parents.front();
        if (parent->left == NULL) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            parents.pop();
        }        
        parents.push(newNode);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */