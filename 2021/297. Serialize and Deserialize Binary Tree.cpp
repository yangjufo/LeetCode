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
        if (root == NULL) return "#";
        return to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return deserialize(data, start);
    }
    
    TreeNode* deserialize(string& data, int& start) {
        if (start >= data.length()) return NULL;
        if (data[start] == '#') {
            start++;
            return NULL;
        }
        
        int flag = 1, num = 0;
        
        if (data[start] == '-') {
            flag = -1;
            start++;
        }
        while (start < data.length() && data[start] != '#') {
            num = num * 10 + data[start] - '0';
            start++;            
        }
        start++;
        TreeNode* root = new TreeNode(num * flag);
        root->left = deserialize(data, start);
        root->right = deserialize(data, start);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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
        string str;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while (!treeQueue.empty()) {
            root = treeQueue.front();
            treeQueue.pop();            
            str += (root == NULL ? "x" : to_string(root->val)) + "#";            
            if (root != NULL) {
                treeQueue.push(root->left);                        
                treeQueue.push(root->right);            
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        queue<TreeNode*> treeQueue;        
        int start = 0, count = -1;
        while (start < data.length()) {
            count++;
            string valStr;
            while (data[start] != '#') {
                valStr += data[start];
                start++;
            }
            start++;
            TreeNode* node = NULL;
            if (valStr != "x") {
                node = new TreeNode(stoi(valStr));
                treeQueue.push(node);
            }
            
            if (root == NULL) {
                root = node;                      
            } else {
                if (count == 1) {
                    treeQueue.front()->left = node;
                } else if(count == 2) {
                    treeQueue.front()->right = node;
                    treeQueue.pop();
                    count = 0;
                }                                
            }
        }
        return root;
    }        
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));