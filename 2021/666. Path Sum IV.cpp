class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<int> nodes(16, -1);
        for (int n : nums) {
            int val = n % 10;
            n /= 10;
            int pos = n % 10;
            n /= 10;
            int depth = n % 10;
            nodes[(int)pow(2, depth - 1) + pos - 2] = val;
        }    
        return sum(nodes, 1, 0);
    }
    
    int sum(vector<int>& nodes, int index, int curr) {
        if (index >= 16 || nodes[index - 1] == -1) return curr;
        curr += nodes[index - 1];
        if (index * 2 >= 16) {
            return curr;
        }
        int res = 0;
        if (nodes[index * 2 - 1] != -1) {
            res = sum(nodes, index * 2, curr);
        }
        if (nodes[index * 2] != -1) {
            res += sum(nodes, index * 2 + 1, curr);
        }
        return res == 0 ? curr : res;
    }
};