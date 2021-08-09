class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> indexes;
        for (int i = 0; i < arr.size(); i++) {
            indexes.push_back({arr[i], i});
        }
        sort(indexes.begin(), indexes.end());
        vector<int> res(arr.size(), 0);
        int rank = 1;
        for (int i = 0; i < indexes.size(); i++) {
            if (i != 0 && indexes[i].first > indexes[i - 1].first) {
                rank++;
            }
            res[indexes[i].second] = rank;
        }
        return res;
    }
};