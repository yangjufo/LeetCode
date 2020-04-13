import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public int[] processQueries(int[] queries, int m) {        
        LinkedList<Integer> ml = new LinkedList<>(IntStream.range(1, m + 1).boxed().collect(Collectors.toList()));
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = ml.indexOf(queries[i]);
            ml.remove(queries[i]);
            ml.add(0, queries[i]);
        }
        return ans;
    }
}