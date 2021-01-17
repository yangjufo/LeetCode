/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == NULL) return "";
        string s = to_string(root->val);
        s += "#" + to_string((root->children).size());
        for (Node* child : root->children) {
            s += "$" + serialize(child);
        }
        return s;        
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int i = 0;
        return desrialize(data, i);
    }
    
    Node* desrialize(string& data, int& i) {        
        if (data.empty()) return NULL;
        int num = 0;
        while (isdigit(data[i])) {
            num = num * 10 + data[i] - '0';
            i++;
        }
        Node* root = new Node(num);
        int childCount = 0;
        i++;
        while (isdigit(data[i])) {
            childCount = childCount * 10 + data[i] - '0';
            i++;
        }
        i++;
        for (int j = 0; j < childCount; j++) {
            (root->children).push_back(desrialize(data, i));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));