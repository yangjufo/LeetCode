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

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& left, vector<int>& right) {
           return left[1] > right[1]; 
        });
        int total = 0;
        for (vector<int>& box : boxTypes) {
            if (truckSize <= 0) break;
            int pick = min(truckSize, box[0]);
            truckSize -= pick;
            total += pick * box[1];
        }
        return total;
    }
};