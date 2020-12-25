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
        if (root == NULL) return "x#";
        string res = to_string(root->val) + "#";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {        
        int start = 0;
        return helper(data, start);
    }
    
    TreeNode* helper(string& data, int& start) {
        string valStr;
        while (start < data.length() && data[start] != '#') {
            valStr += data[start];
            start++;
        }
        start++;
        if (valStr == "x") return NULL;
        TreeNode* root = new TreeNode(stoi(valStr));
        root->left = helper(data, start);
        root->right = helper(data, start);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));