class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        visited[start] = true;
        queue<int> indexes;
        indexes.push(start);
        while (!indexes.empty()) {
            int curr = indexes.front();
            indexes.pop();
            if (arr[curr] == 0) return true;
            if (curr + arr[curr] < arr.size() && curr + arr[curr] >= 0 && !visited[curr + arr[curr]]) {
                indexes.push(curr + arr[curr]);
                visited[curr + arr[curr]] = true;
            }
            if (curr - arr[curr] < arr.size() && curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) {
                indexes.push(curr - arr[curr]);
                visited[curr - arr[curr]] = true;
            }
        }
        return false;
    }
};