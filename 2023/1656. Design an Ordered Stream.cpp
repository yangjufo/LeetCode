class OrderedStream {
public:
    vector<string> values;
    int index = 0;
    OrderedStream(int n) {
        values.resize(n);
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        values[idKey - 1] = value;
        if (idKey - 1 > index) {
            return res;
        }
        while (index < values.size() && !values[index].empty()) {
            res.push_back(values[index]);
            index += 1;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */