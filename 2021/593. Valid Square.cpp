class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return valid(p1, p2, p3, p4) || valid(p1, p3, p2, p4) || valid(p1, p2, p4, p3);
    }
    
    bool valid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {     
        return p1[0] + p3[0] == p2[0] + p4[0] && p1[1] + p3[1] == p2[1] + p4[1] && (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]) == (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]) && (p2[1] - p4[1]) * (p1[1] - p3[1]) == -(p2[0] - p4[0]) * (p1[0] - p3[0]) && (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]) > 0;
    }
};