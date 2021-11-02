class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ",";
        stack<string> root;
        string curr;
        for (char c : preorder) {
            if (c == ',') {     
                while (curr == "#" && !root.empty() && root.top() == "#") {
                    if (root.size() < 2) return false;
                    root.pop();
                    if (root.top() == "#") return false;
                    root.pop();
                }
                root.push(curr);                
                curr.clear();
            } else {
                curr += c;
            }            
        }
        return root.size() == 1 && root.top() == "#";
    }    
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int index = 0;
        return traverse(preorder, index) && index >= preorder.length();
    }
    
    bool traverse(string& preorder, int& index) {
        string curr;
        while (index < preorder.length() && preorder[index] != ',') {
            curr += preorder[index];
            index++;
        }
        index++;
        if (curr.empty()) return false;
        if (curr == "#") {
            return true;
        }
        return traverse(preorder, index) && traverse(preorder, index);
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> nodes;
        int i = 0;
        while (i < preorder.length()) {        
            if (i != 0 && nodes.empty()) {
                return false;
            }
            if (preorder[i] == '#') {
                if (nodes.empty()) {
                    return i + 1 == preorder.length();
                }
                do {
                    nodes.back()++;
                    if (nodes.back() == 2) {
                        nodes.pop_back();
                    } else {
                        break;
                    }
                } while (!nodes.empty());                              
            } else {
                nodes.push_back(0);
            }             
            while (i < preorder.length() && preorder[i] != ',') {
                i++;
            }                        
            i++;
        }
        return nodes.empty();
    }
};