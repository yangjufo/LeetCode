/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> toVisit;
        toVisit.push(node);
        while (!toVisit.empty()) {
            UndirectedGraphNode* cur = toVisit.front();
            toVisit.pop();
            for (UndirectedGraphNode* neigh : cur -> neighbors) {
                if (mp.find(neigh) == mp.end()) {
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh -> label);
                    mp[neigh] = neigh_copy;
                    toVisit.push(neigh);
                }
                mp[cur] -> neighbors.push_back(mp[neigh]);
            }
        }
        return copy; 
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};