class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        vector<pair<int, int>> funcStack;
        for (string log : logs) {
            int split1 = log.find(":"), split2 = log.find(":", split1 + 1);
            int id = stoi(log.substr(0, split1)), time = stoi(log.substr(split2 + 1));
            string op = log.substr(split1 + 1, split2 - split1 - 1);
            if (op == "end") {
                auto func = funcStack.back();
                funcStack.pop_back();
                res[id] += time - func.second + 1;
                if (!funcStack.empty()) {
                    funcStack.back().second = time;
                }                
            } else {
                if (!funcStack.empty()) {
                    res[funcStack.back().first] += time - funcStack.back().second - 1;
                }
                funcStack.push_back({id, time});
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0), funcStack;        
        int prevTime = 0;
        for (string log : logs) {
            int split1 = log.find(":"), split2 = log.find(":", split1 + 1);
            int id = stoi(log.substr(0, split1)), time = stoi(log.substr(split2 + 1));
            string op = log.substr(split1 + 1, split2 - split1 - 1);
            if (op == "start") {
                if (!funcStack.empty()) {
                    res[funcStack.back()] += time - prevTime;
                }                
                prevTime = time;
                funcStack.push_back(id);
            } else {                
                res[id] += time - prevTime + 1;
                funcStack.pop_back();
                prevTime = time + 1;
            }
        }
        return res;
    }
};