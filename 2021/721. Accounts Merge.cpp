class Solution {
public:
    unordered_map<string, string> parents;
    unordered_map<string, int> ranks;
    unordered_map<string, string> emailAccount;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (vector<string>& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                parents[account[i]] = account[i];
                ranks[account[i]] = 0;
                emailAccount[account[i]] = account[0];
            }
        }        
        for (vector<string>& account : accounts) {
            for (int i = 1; i < account.size() - 1; i++) {
                merge(account[i], account[i + 1]);
            }
        }        
        
        unordered_map<string, vector<string>> groups;
        for (auto& iter : emailAccount) {
            string parent = find(iter.first);            
            groups[parent].push_back(iter.first);
        }
        
        vector<vector<string>> res;
        for (auto& iter : groups) {
            vector<string> one = iter.second;
            sort(one.begin(), one.end());
            one.insert(one.begin(), emailAccount[one[0]]);
            res.push_back(one);
        }
        
        return res;
        
    }
    
    string find(string target) {
        if (parents[target] != target) {
            parents[target] = find(parents[target]);
        }
        return parents[target]; 
    }
    
    void merge(string& left, string& right) {
        string pLeft = find(left), pRight = find(right);
        if (pLeft != pRight) {
            if (ranks[pLeft] < ranks[pRight]) {
                parents[pLeft] = parents[pRight];
            } else {
                parents[pRight] = parents[pLeft];
                if (ranks[pLeft] == ranks[pRight]) {
                    ranks[pLeft]++;
                }
            }
        }
    }
    
};