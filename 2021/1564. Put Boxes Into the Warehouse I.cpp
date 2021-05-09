class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        vector<int> minHeight;
        for (int i = 0; i < warehouse.size(); i++) {
            minHeight.push_back(minHeight.empty() ? warehouse[i] : min(warehouse[i], minHeight.back()));
        }
        int wIndex = warehouse.size() - 1, bIndex = 0;
        while (wIndex >= 0 && bIndex < boxes.size()) {            
            if (boxes[bIndex] <= minHeight[wIndex]) {
                bIndex++;
            }
            wIndex--;            
        }
        return bIndex;
    }
};