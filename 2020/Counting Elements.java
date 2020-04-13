import java.util.Arrays;
import java.util.Set;
import java.util.stream.Collectors;

class Solution {
    public int countElements(int[] arr) {
        Set<Integer> arrSet = Arrays.stream(arr).boxed().collect(Collectors.toSet());        
        return Arrays.stream(arr).map(a -> arrSet.contains(a + 1) ? 1 : 0).sum();
    }
}