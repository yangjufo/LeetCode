import java.util.HashMap;
import java.util.Map;

class Solution {
    public String entityParser(final String text) {
        Map<String, String> map = new HashMap<>();
        map.put("&quot;", "\"");
        map.put("&apos;", "'");
        map.put("&amp;", "&");
        map.put("&gt;", ">");
        map.put("&lt;", "<");
        map.put("&frasl;", "/");
        String ans = text;
        for (Map.Entry<String, String> entry: map.entrySet()) {
            ans.replaceAll(entry.getKey(), entry.getValue());
        }
        return ans;
    }
}