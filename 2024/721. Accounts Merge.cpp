
class Solution {
public:
    string find(unordered_map<string, string>& parents, const string& email) {
        if (parents[email] != email) {
            parents[email] = find(parents, parents[email]);
        }
        return parents[email];
    }

    void merge(unordered_map<string, string>& parents,
               unordered_map<string, int>& ranks, string& left, string& right) {
        string pLeft = find(parents, left), pRight = find(parents, right);
        if (pLeft == pRight) {
            return;
        }
        if (ranks[pLeft] > ranks[pRight]) {
            parents[pRight] = pLeft;
            return;
        }
        parents[pLeft] = pRight;
        if (ranks[pLeft] == ranks[pRight]) {
            ranks[pRight] += 1;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_to_name;
        unordered_map<string, string> parents;
        unordered_map<string, int> ranks;
        for (vector<string>& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                email_to_name[account[i]] = account[0];
                parents[account[i]] = account[i];
                ranks[account[i]] = 0;
            }
        }
        for (vector<string>& account : accounts) {
            for (int i = 1; i < account.size() - 1; i++) {
                merge(parents, ranks, account[i], account[i + 1]);
            }
        }
        unordered_map<string, vector<string>> groups;
        for (auto& [email, name] : email_to_name) {
            string key = find(parents, email);
            groups[key].push_back(email);
        }

        vector<vector<string>> res;
        for (auto& [key, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), email_to_name[key]);
            res.push_back(emails);
        }
        return res;
    }
};