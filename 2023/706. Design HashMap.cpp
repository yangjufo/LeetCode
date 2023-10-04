class Node {
public:
    int key;
    int value;
    Node *prev, *next;

    Node(int _key, int _value) : key(_key), value(_value), prev(NULL), next(NULL) {}

};

class MyHashMap {
public:
    int capacity = 2069;
    vector<Node*> nodes;
    MyHashMap() {
        nodes.resize(capacity, NULL);
    }

    void put(int key, int value) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            nodes[index] = new Node(-1, -1);
        }
        Node* prev = nodes[index], *head = nodes[index]->next;
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            prev = head;
            head = head->next;
        }
        prev->next = new Node(key, value);
    }

    int get(int key) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            return -1;
        }
        Node* head = nodes[index]->next;
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = key % capacity;
        if (nodes[index] == NULL) {
            return;
        }
        Node* prev = nodes[index], *head = nodes[index]->next;
        while (head != NULL) {
            if (head->key == key) {
                prev->next = head->next;
                delete head;
                break;
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