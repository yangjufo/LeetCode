
public String[] orderedConfiguration(String configuration) {
    String[] invalidReturn = {"Invalid configuration"};
    if (!configuration.matches("[A-Za-z0-9|]+")) {
        return invalidReturn;
    }
    configuration += '|';
    Map<Integer, String> configs = new HashMap<>();
    int i = 0;
    while (i < configuration.length()) {
        int index = 0;
        for (int j = 0; j < 4; j++, i++) {
        char c = configuration.charAt(i);
        if (!(c >= '0' && c <= '9')) {
            return invalidReturn;
        }
        index = index * 10 + c - '0';
        }
        StringBuilder valueBuilder = new StringBuilder();
        while (i < configuration.length() && configuration.charAt(i) != '|') {
        char c = configuration.charAt(i);
        valueBuilder.append(c);
        i += 1;
        }
      if (configs.containsKey(index)) {
                return invalidReturn;
            }
        configs.put(index, valueBuilder.toString());
        i += 1;
    }
    List<Map.Entry<Integer, String>> list = new ArrayList<>(configs.entrySet());
    Collections.sort(list, Comparator.comparingInt(e->e.getKey()));
    ArrayList<String> res = new ArrayList<>();
    for (int j = 1; j < list.size() + 1; j++) {
        if (list.get(j - 1).getKey() != j) {
        return invalidReturn;
        }
        res.add(list.get(j - 1).getValue());
    }
    return res.toArray(new String[0]);
}
