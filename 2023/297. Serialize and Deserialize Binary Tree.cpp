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
        string res;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = queue.front();
                queue.pop();
                if (curr == NULL) {
                    res += "##";
                } else {
                    res += to_string(curr->val) + "#";
                    queue.push(curr->left);
                    queue.push(curr->right);
                }
            }
        }
        return res;
    }

    int getNext(string& data, int& index) {
        int val = 0, flag = 1;
        if (data[index] == '-') {
            flag = -1;
            index++;
        }
        while (data[index] != '#') {
            val = val * 10 + data[index] - '0';
            index++;
        }
        index++;
        return val * flag;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "##") {
            return NULL;
        }
        int index = 0;
        queue<TreeNode*> queue;
        TreeNode* root = new TreeNode(getNext(data, index));
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* parent = queue.front();
                queue.pop();
                if (data[index] == '#') {
                    index += 2;
                } else {
                    TreeNode* left = new TreeNode(getNext(data, index));
                    parent->left = left;
                    queue.push(left);
                }
                if (data[index] == '#') {
                    index += 2;
                } else {
                    TreeNode* right = new TreeNode(getNext(data, index));
                    parent->right = right;
                    queue.push(right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));