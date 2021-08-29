class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<int> len(101, 0);
        for (string& n : nums) {
            len[n.length()]++;
        }
        int i = 100, count = 0;
        while (count < k) {
            count += len[i];
            i--;
        }
        i++;
        count -= len[i];
        priority_queue<string> pq;
        for (string& n : nums) {
            if (n.length() == i) {
                pq.push(n);                
            }            
        }
        while (count + 1 < k) {
            pq.pop();
            count++;
        }
        return pq.top();
    }
};