class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int right = 0;
        for (int c : cookies) {
            right += c;
        }
        int left = (right + k - 1) / k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            vector<bool> visited(cookies.size(), false);
            if (!dis(cookies, visited, mid, k - 1, 0)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool dis(vector<int>& cookies, vector<bool>& visited, int target, int k, int sum) {
        if (k < 0) return false;
        bool more = false;
        for (int i = 0; i < cookies.size(); i++) {
            if (!visited[i]) {
                more = true;
                visited[i] = true;
                if (sum + cookies[i] <= target) {
                    if (dis(cookies, visited, target, k, sum + cookies[i])) {
                        return true;
                    }
                } else if (cookies[i] <= target) {
                    if (dis(cookies, visited, target, k - 1, cookies[i])) {
                        return true;
                    }
                }
                visited[i] = false;
            }
        }
        return !more;
    }
};