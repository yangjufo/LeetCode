class Solution {
public:
    vector<string> generateParenthesis(int n) {
          if (n == 1)
            return vector<string>{"()"};
        vector<string> tmp_ret = generateParenthesis(n - 1);
        vector<string> tmp_res;
        for (int j = 0; j < tmp_ret.size(); j++){
            string tmp_s = tmp_ret[j];
            for (int i = 0; i < tmp_s.length(); i++){                
                if (tmp_s[i + 1] != '(' && (i > 0 && tmp_s[i - 1] !='('))
                    continue;
                string tmp_ss = tmp_s;
                if (find(tmp_res.begin(), tmp_res.end(), tmp_ss.insert(i, "()")) == tmp_res.end())
                    tmp_res.push_back(tmp_ss);                
            }
        }
        return tmp_res;     
        
    }
};