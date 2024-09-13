struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key_ = 0, int val_ = 0) {
        key = key_;
        val = val_;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int capacity_ = 0;
    Node* head = NULL, *tail = NULL;
    unordered_map<int, Node*> map;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        Node* node = NULL;
        if (map.find(key) != map.end()) {
            node = map[key];
            remove(node);
            node->val = value;
        } else {
            if (map.size() == capacity_) {
                map.erase(tail->prev->key);
                remove(tail->prev);
            }
            node = new Node(key, value);
        }
        map[key] = node;
        insert(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */