class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, array<int, 2>>> pq;        
        double total = 0;
        for (auto& class1 : classes) {
            pq.push({profit(class1[0], class1[1]), {class1[0], class1[1]}});
            total += class1[0] * 1.0 / class1[1];
        }
        for (int i = 0; i < extraStudents; i++) {
            auto curr = pq.top().second;
            pq.pop();
            pq.push({profit(curr[0] + 1, curr[1] + 1), {curr[0] + 1, curr[1] + 1}});            
            total += profit(curr[0], curr[1]);
        }       
        return total / classes.size();
    }
    
    double profit(int pass, int total) {
        return (pass + 1) * 1.0 / (total + 1) - pass * 1.0 / total;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comparator = [](array<long, 2>& left, array<long, 2>& right) {
            return (left[1] - left[0]) * (right[1] * right[1] + right[1]) < (right[1] - right[0]) * (left[1] * left[1] + left[1]);
        };
        priority_queue<array<long, 2>, vector<array<long, 2>>, decltype(comparator)> pq(comparator);
        for (auto& class1 : classes) {
            pq.push({class1[0], class1[1]});
        }        
        for (int i = 0; i < extraStudents; i++) {
            auto curr = pq.top();
            pq.pop();
            curr[0]++;
            curr[1]++;
            pq.push(curr);
        }
        double total = 0;
        while (!pq.empty()) {
            total += pq.top()[0] * 1.0 / pq.top()[1];
            pq.pop();
        }
        return total / (classes.size());
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto comparator = [](array<int, 2>& left, array<int, 2>& right) {
            return (double)(left[0] + 1) / (left[1] + 1) - (double)left[0] / left[1] < (double)(right[0] + 1) / (right[1] + 1) - (double)right[0] / right[1];
        };
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(comparator)> pq(comparator);
        double sum = 0;
        for (vector<int>& c : classes) {
            sum += (double)c[0] / c[1];
            pq.push({c[0], c[1]});
        }        
        for (int i = 0; i < extraStudents; i++) {
            auto top = pq.top();
            pq.pop();
            sum += (double)(top[0] + 1) / (top[1] + 1) - (double)top[0] / top[1];
            pq.push({top[0] + 1, top[1] + 1});            
        }
        return sum / classes.size();
    }
};