/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode* m_bTree;
public:
    BSTIterator(TreeNode *root) {
        m_bTree = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (m_bTree == NULL)
            return false;
        else
            return true;        
    }
    /** @return the next smallest number */
    int next() {                
        TreeNode* tmp, *prev;
        if (m_bTree->left != NULL){            
            tmp = m_bTree->left;
            prev = m_bTree;
            while (tmp->left != NULL){
                prev = prev->left;
                tmp = tmp->left;
            }                            
            prev->left = tmp->right;                        
            return tmp->val;
        }        
        else{
            tmp = m_bTree;
            m_bTree = m_bTree->right;
            return tmp->val;            
        }                                
    }
        
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */