import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

class Solution {
    public List<String> stringMatching(String[] words) {
        Set<String> ans = new HashSet<>();
        for (String word: words) {
            for (String subWord: words) {
                if (!word.equals(subWord) && word.indexOf(subWord) !=-1) {
                    ans.add(subWord);
                }
            }
        }
        return new ArrayList<>(ans);
    }
}