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