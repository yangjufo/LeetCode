
class Solution {
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        Map<String, List<Pair<Integer, String>>> userWebsite = new HashMap<>();
        for (int i = 0; i < username.length; i++) {
            if (!userWebsite.containsKey(username[i])) {
                userWebsite.put(username[i], new ArrayList<>());
            }
            userWebsite.get(username[i]).add(new Pair<>(timestamp[i], website[i]));
        }
        Map<String, Integer> patternCount = new HashMap<>();
        for (Map.Entry<String, List<Pair<Integer, String>>> entry : userWebsite.entrySet()) {
            Set<String> seenPattern = new HashSet<>();
            Collections.sort(entry.getValue(), Comparator.comparing(p -> p.getKey()));
            for (int i = 0; i < entry.getValue().size() - 2; i++) {
                for (int j = i + 1; j < entry.getValue().size() - 1; j++) {
                    for (int k = j + 1; k < entry.getValue().size(); k++) {
                        StringBuilder sb = new StringBuilder();
                        sb.append(entry.getValue().get(i).getValue()).append("-")
                                .append(entry.getValue().get(j).getValue()).append("-")
                                .append(entry.getValue().get(k).getValue());
                        String pattern = sb.toString();
                        if (seenPattern.contains(pattern)) {
                            continue;
                        }
                        seenPattern.add(pattern);
                        patternCount.put(pattern, patternCount.getOrDefault(pattern, 0) + 1);
                    }
                }
            }
        }

        List<Map.Entry<String, Integer>> list = new ArrayList<>(
                patternCount.entrySet());
        list.sort(Map.Entry.comparingByValue());
        int maxCount = list.getLast().getValue();
        String ans = list.getLast().getKey();
        for (Map.Entry<String, Integer> e : list) {
            if (e.getValue() == maxCount && e.getKey().compareTo(ans) < 0) {
                ans = e.getKey();
            }
        }

        return Arrays.asList(ans.split("-"));

    }
}