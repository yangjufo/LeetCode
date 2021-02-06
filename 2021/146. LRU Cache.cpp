class Node {
public:
    int key, value;
    Node *prev, *next;
    
    Node(int _key, int _value): key(_key), value(_value), prev(NULL), next(NULL){};
    
};

class LRUCache {
public:
    
    int capacity;
    unordered_map<int, Node*> nodeMap;
    Node *head, *tail;
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) return -1;
        Node* node = nodeMap[key];
        update(node);                        
        return node->value;
    }
    
    void put(int key, int value) {
        if (nodeMap.find(key) == nodeMap.end()) {
            Node* node = new Node(key, value);
            insert(node);            
            nodeMap[key] = node;
            if (nodeMap.size() > capacity) {
                Node* toDelete = tail->prev;
                erase(toDelete);
                nodeMap.erase(toDelete->key);
                delete toDelete;
            }
        } else {
            Node *node = nodeMap[key];
            node->value = value;
            update(node);            
        }
    }
    
    void update(Node* node) {
        erase(node);
        insert(node);
    }
    
    void insert(Node* node) {
        // add to head
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void erase(Node* node) {
        // delete
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */