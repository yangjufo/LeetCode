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

 struct LNode
{
    int key;
    int val;
    LNode* prev, *next;
    LNode(int _key, int _val) : key(_key), val(_val), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    unordered_map<int, LNode*> nodes;    
    int capacity, count;
    LNode *head, *tail;
    LRUCache(int capacity) {
        head = new LNode(0, 0);
        tail = new LNode(0, 0);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        count = 0;
    }
    
    int get(int key) {
        if (nodes.find(key) == nodes.end()) {
            return -1;
        }
        // delete the node
        LNode* node = nodes[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;                
        
        // insert in the front
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (nodes.find(key) == nodes.end()) {
            // insert in the front
            LNode* newNode = new LNode(key, value);
            insert(newNode);        
            count++;
            nodes[key] = newNode;        

            if (count > capacity) {
                remove();
            }   
        } else {
            nodes[key]->val = value;
            get(key);
        }        
    }
    
    void insert(LNode* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void remove() {
        LNode* toDelete = tail->prev;
        toDelete->prev->next = tail;
        tail->prev = toDelete->prev;
        nodes.erase(toDelete->key);
        delete toDelete;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */