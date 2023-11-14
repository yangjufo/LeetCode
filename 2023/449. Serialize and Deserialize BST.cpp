/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string& pre) {
        if (root == NULL) {
            return;
        }
        pre += to_string(root->val) + "#";
        preorder(root->left, pre);
        preorder(root->right, pre);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string pre;
        preorder(root, pre);
        cout << pre << endl;
        return pre;
    }

    int getNext(string& data, int& index) {
        int val = 0;
        while (data[index] != '#') {
            val = val * 10 + data[index] - '0';
            index++;
        }
        index++;
        return val;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        stack<TreeNode*> stack;
        int index = 0;
        TreeNode* root = new TreeNode(getNext(data, index));
        stack.push(root);
        while (index < data.length()) {
            TreeNode* node = new TreeNode(getNext(data, index));
            TreeNode* prev = NULL;
            while (!stack.empty() && stack.top()->val < node->val) {
                prev = stack.top();
                stack.pop();
            }
            if (prev != NULL) {
                prev->right = node;
            } else if (!stack.empty()) {
                stack.top()->left = node;
            }
            stack.push(node);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;