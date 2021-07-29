class Solution {
public:    
    bool verifyPreorder(vector<int>& preorder) {        
        stack<int> roots;
        int low = 0;
        for (int p : preorder) {
            if (p < low) return false;
            while (!roots.empty() && p > roots.top()) {
                low = roots.top();
                roots.pop();
            }
            roots.push(p);
        }
        return true;
    }               
};

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = 0;
        stack<int> nodes;
        for (int p : preorder) {
            if (p < low) return false;
            while (!nodes.empty() && p > nodes.top()) {
                low = nodes.top();
                nodes.pop();
            }
            nodes.push(p);
        }
        return true;        
    }
};