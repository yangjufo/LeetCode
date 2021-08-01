class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i + 1 >= citations[i]) return (i + 1 == citations[i]) ? i + 1 : i;
        }
        return citations.size();
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int c : citations) {
            count[min(n, c)]++;
        }
        int k = n;
        for (int s = count[k]; k > s; s += count[k]) {
            k--;
        }
        return k;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int c : citations) {
            count[min(n, c)]++;
        }
        
        int k = n;
        for (int s = count[k]; k > s; s += count[k]) {
            k--;
        }
        return k;
    }
};