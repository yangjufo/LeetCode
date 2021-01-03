class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });
        int total = 0;
        for (vector<int>& box : boxTypes) {
            if (box[0] <= truckSize) {
                total += box[0] * box[1];
                truckSize -= box[0];
            } else {
                total += box[1] * truckSize;
                break;
            }            
        }
        return total;
    }
};