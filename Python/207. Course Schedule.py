class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        edges = dict()
        for pair in prerequisites:
            if pair[1] not in edges:
                edges[pair[1]] = set([pair[0]])
            else:
                edges[pair[1]].add(pair[0])
        visited = set()
        def dfs(start, paths):
            if start in paths:
                return False
            if start in visited:
                return True
            visited.add(start)
            paths.add(start)
            if start in edges:
                for neigh in edges[start]:
                    ans = dfs(neigh, paths)
                    if ans is False:
                        return False
            paths.remove(start)
            return True
        for i in range(numCourses):
            if not dfs(i, set()):
                return False
        return True
            