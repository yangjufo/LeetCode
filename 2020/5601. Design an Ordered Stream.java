class OrderedStream {
    
    int ptr;
    int cap;
    String[] values;
    
    public OrderedStream(int n) {
        cap = n;
        ptr = 1;
        values = new String[n + 1];
    }
    
    public List<String> insert(int id, String value) {
        values[id] = value;
        ArrayList<String> ret = new ArrayList<>();
        if (ptr == id) {
            for (; id <= cap && values[id] != null && !values[id].isEmpty(); id++) {
                ret.add(values[id]);
            }
            ptr = id;
        }        
        return ret;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(id,value);
 */