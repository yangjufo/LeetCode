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