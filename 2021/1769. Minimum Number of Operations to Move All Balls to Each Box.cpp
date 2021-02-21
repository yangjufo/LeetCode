class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.length(), leftCount = 0, rightCount = 0, leftSum = 0, rightSum = 0; 
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {            
            leftSum += leftCount;
            res[i] += leftSum;
            if (boxes[i] == '1') {                                
                leftCount++;
            }            
        }                
        for (int i = len - 1; i >= 0; i--) {
            rightSum += rightCount;
            res[i] += rightSum;
            if (boxes[i] == '1') {
                rightCount++;
            }
        }
        
        return res;
    }
};