class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quickSelect(points, 0, points.size() - 1, K);
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(points[i]);
        }
        return res;
    }
    
    void quickSelect(vector<vector<int>>& points, int left, int right, int K) {        
        if (left >= right) return;
        int pivot = rand() % (right - left) + left;
                
        pivot = partition(points, left, right, pivot);        
        if (pivot == K - 1) return;
        if (pivot > K - 1) quickSelect(points, left, pivot - 1, K);
        else quickSelect(points, pivot + 1, right, K);
    }
    
    int partition(vector<vector<int>>& points, int left, int right, int pivot) {
        swap(points[right], points[pivot]);
        int smallIndex = left, pivotDis = points[right][0] * points[right][0] + points[right][1] * points[right][1];
        for (int i = left; i < right; i++) {
            if (points[i][0] * points[i][0] + points[i][1] * points[i][1] <= pivotDis) {
                swap(points[i], points[smallIndex]);
                smallIndex++;
            }
        }
        swap(points[smallIndex], points[right]);
        return smallIndex;
    }
};