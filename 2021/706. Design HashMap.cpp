class MyHashMap {
public:
    vector<int> values;
    vector<bool> valid;
    /** Initialize your data structure here. */
    MyHashMap() {        
        values.resize(1000001, 0);
        valid.resize(1000001, false);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        values[key] = value;
        valid[key] = true;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (!valid[key]) return -1;
        return values[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        valid[key] = false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class Node {
public:
    int key, val;
    Node* next;
    
    Node(int _key, int _val): key(_key), val(_val), next(NULL) {}
};

class MyHashMap {
public:
    int mod = 2069;
    vector<Node*> buckets;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets.resize(mod, new Node(0, 0));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashKey = key % mod;        
        Node *prev = buckets[hashKey], *node;
        while (prev->next != NULL && prev->next->key != key) {
            prev = prev->next;
        }        
        if (prev->next == NULL) {
            node = new Node(key, value);
            prev->next = node;            
        } else {
            prev->next->val = value;
        }        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashKey = key % mod;
        Node *node = buckets[hashKey]->next;
        while (node != NULL) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashKey = key % mod;
        Node *prev = buckets[hashKey];
        while (prev->next != NULL && prev->next->key != key) {
            prev = prev->next;
        }            
        if (prev->next != NULL) {
            Node *rNode = prev->next;
            prev->next = rNode->next;
            delete rNode;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class Node {
public:
    int key;
    int val;
    Node *prev, *next;
    
    Node(int _key, int _val): key(_key), val(_val), prev(NULL), next(NULL) {}
};

class MyHashMap {
public:
    int capacity = 2069;
    vector<Node*> nodes;    
    /** Initialize your data structure here. */
    MyHashMap() {        
        nodes.resize(2069, NULL);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            nodes[index] = new Node(-1, -1);
        }
        Node* head = nodes[index]->next, *prev = nodes[index];
        while (head != NULL) {
            if (head->key == key) {
                head->val = value;
                return;
            }
            prev = head;
            head = head->next;
        }
        Node* node = new Node(key, value);
        prev->next = node;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            return -1;
        }
        Node *head = nodes[index]->next;
        while (head != NULL) {
            if (head->key == key) {
                return head->val;
            }
            head = head->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            return;
        }
        Node *head = nodes[index]->next, *prev = nodes[index];
        while (head != NULL) {
            if (head->key == key) {
                prev->next = head->next;
                delete head;
                return;
            }          
            prev = head;
            head = head->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

 class MyHashMap {
public:
    int size = 1234;
    vector<vector<pair<int, int>>> nums;
    /** Initialize your data structure here. */
    MyHashMap() {
        nums.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % size;
        int pos = nums[index].size();
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i].first == key) {
                nums[index][i].second = value;
                return;
            } else if (nums[index][i].first == -1) {
                pos = i;
            }
        }
        if (pos >= nums[index].size()) {
            nums[index].push_back({key, value});
        } else {
            nums[index][pos] = {key, value};            
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % size;
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i].first == key) {
                return nums[index][i].second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % size;        
        for (int i = 0; i < nums[index].size(); i++) {
            if (nums[index][i].first == key) {
                nums[index][i] = {-1, -1};
                return;
            }
        }        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */