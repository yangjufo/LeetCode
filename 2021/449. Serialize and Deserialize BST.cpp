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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string str;
        preorder(root, str);
        return str.substr(0, str.length() - 1);
    }
    
    void preorder(TreeNode* root, string& str) {
        if (root == NULL) return;       
        str += to_string(root->val) + "#";
        preorder(root->left, str);
        preorder(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return deserialize(data, start, INT_MIN, INT_MAX);
    }
    
    TreeNode* deserialize(string& data, int& start, int minVal, int maxVal) {
        if (start >= data.length()) return NULL;
        int num = 0, i = start;
        while (i < data.length() && isdigit(data[i])) {
            num = num * 10 + (data[i] - '0');
            i++;
        }
        if (num < minVal || num > maxVal) {
            return NULL;
        }
        start = i + 1;
        TreeNode* root = new TreeNode(num);
        root->left = deserialize(data, start, minVal, num);
        root->right = deserialize(data, start, num, maxVal);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;