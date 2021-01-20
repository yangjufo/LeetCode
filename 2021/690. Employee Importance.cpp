/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, int> importance;
    unordered_map<int, vector<int>> subordinates;
    int sum = 0;
    int getImportance(vector<Employee*> employees, int id) {
       
        for (Employee* e : employees) {
            importance[e->id] = e->importance;
            subordinates[e->id] = e->subordinates;
        }                
        dfs(id);
        return sum;
    }
    
    void dfs(int id) {
        sum += importance[id];
        for (int i : subordinates[id]) {
            dfs(i);
        }
    }
    
};