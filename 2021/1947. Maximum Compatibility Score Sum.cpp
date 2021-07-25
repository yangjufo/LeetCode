class Solution {
public:
    vector<vector<int>> mem;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {        
        mem.resize(students.size(), vector<int>(mentors.size()));
        vector<int> studentBits, mentorBits;
        for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < mentors.size(); j++) {
                int sum = 0;
                for (int k = 0; k < students[i].size(); k++) {
                    sum += (students[i][k] == mentors[j][k]) ? 1 : 0;
                }
                mem[i][j] = sum;
            } 
        }            
        vector<bool> visited(mentors.size(), false);
        return dfs(students.size(), mentors.size(), visited, 0);
        
    }
    
    int dfs(int students, int mentors, vector<bool>& visited, int index) {
        if (index >= students) return 0;
        int curr = 0;
        for (int i = 0; i < mentors; i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr = max(curr, mem[index][i] + dfs(students, mentors, visited, index + 1));
                visited[i] = false;
            }
        }        
        return curr;
    }        
};