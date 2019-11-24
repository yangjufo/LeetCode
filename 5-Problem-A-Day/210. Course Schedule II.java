class Solution {
    static int WHITE = 1;
    static int GRAY = 2;
    static int BLACK = 3;

    boolean isPossible;
    Map<Integer, Integer> color;
    Map<Integer, List<Integer>> adjList;
    List<Integer> order;

    private void init(int numCourses) {
        isPossible = true;
        color = new HashMap<>();
        adjList = new HashMap<>();
        order = new ArrayList<>();

        for (int i = 0; i < numCourses; i++)
            color.put(i, WHITE);
    }

    private void dfs(int node) {
        if (!isPossible)
            return;

        color.put(node, GRAY);

        for (int neighbor : adjList.getOrDefault(node, new ArrayList<Integer>())) {
            if (color.get(neighbor) == WHITE)
                dfs(neighbor);
            else if (color.get(neighbor) == GRAY)
                isPossible = false;
        }

        color.put(node, BLACK);
        order.add(node);
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        init(numCourses);
        for (int i = 0; i < prerequisites.length; i++) {
            int dest = prerequisites[i][0], src = prerequisites[i][1];
            List<Integer> lst = adjList.getOrDefault(src, new ArrayList<Integer>());
            lst.add(dest);
            adjList.put(src, lst);
        }

        for (int i = 0; i < numCourses && isPossible; i++) {
            if (color.get(i) == WHITE)
                dfs(i);
        }

        int[] ans;
        if (isPossible) {
            ans = new int[numCourses];
            for (int i = 0; i < numCourses; i++) {
                ans[i] = order.get(numCourses - i - 1);
            }
        } else
            ans = new int[0];

        return ans;
    }
}
