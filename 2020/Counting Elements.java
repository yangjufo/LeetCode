import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.function.Supplier;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class Solution {
    public int countElements(int[] arr) {
        Set<Integer> arrSet = Arrays.stream(arr).boxed().collect(Collectors.toSet());        
        return Arrays.stream(arr).map(a -> arrSet.contains(a + 1) ? 1 : 0).sum();
    }
}