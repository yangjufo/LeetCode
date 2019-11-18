class TwoSum {
    Map<Integer, Integer> map = new HashMap<>();


    /** Initialize your data structure here. */
    public TwoSum() {
    }

    /** Add the number to an internal data structure.. */
    public void add(int number) {
        map.put(number, map.getOrDefault(number, 0) + 1);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for (int key : map.keySet()) {
            int remain = value - key;
            if (remain == key && map.get(key) >= 2)
                return true;
            if (remain != key && map.containsKey(remain))
                return true;
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such: TwoSum obj = new TwoSum();
 * obj.add(number); boolean param_2 = obj.find(value);
 */
